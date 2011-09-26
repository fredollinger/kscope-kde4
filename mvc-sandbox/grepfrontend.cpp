#include <qdebug.h>
#include <qfileinfo.h>
#include <qtimer.h>
#include <kconfig.h>
#include <kmessagebox.h>
#include <klocale.h>
#include <kglobalsettings.h>
#include "grepfrontend.h"

#define BUILD_STR		"Building symbol database %d of %d"
#define SEARCH_STR		"Search %d of %d"
#define INV_STR			"Possible references retrieved %d of %d"
#define REGEXP_STR		"Symbols matched %d of %d"
#define SEARCHEND_STR	"%d lines"

QString GrepFrontend::s_sProjPath;
uint GrepFrontend::s_nProjArgs;
uint GrepFrontend::s_nSupArgs;

/**
 * Class constructor.
 * @param	bAutoDelete	true to delete the object once the process has
 *						terminated, false otherwise
 */
GrepFrontend::GrepFrontend(bool bAutoDelete) : 
	Frontend(CSCOPE_RECORD_SIZE, bAutoDelete),
	m_state(Unknown),
	m_sErrMsg(""),
	m_bRebuildOnExit(false)
{
	s_nProjArgs=0;
}

/**
 * Class destructor.
 */
GrepFrontend::~GrepFrontend()
{
}

/**
 * Executes a grep process using the given command line arguments.
 * The full path to the grep executable should be set in the "Path" key
 * under the "grep" group.
 * @param	slArgs	Command line arguments for grep
 * @return	true if successful, false otherwise
 */
bool GrepFrontend::run(const QStringList& slArgs)
{
	QStringList slCmdLine;

	// Set the command line arguments
	slCmdLine += slArgs;
	
	// Use verbose mode, if supported
	if (s_nSupArgs & VerboseOut)
		slCmdLine << "-v";
		
	// Project-specific options
	if (s_nProjArgs & Kernel)
		slCmdLine << "-k";
	if (s_nProjArgs & InvIndex)
		slCmdLine << "-q";
	if (s_nProjArgs & NoCompression)
		slCmdLine << "-c";
	if (s_nProjArgs & s_nSupArgs & SlowPathDef)
		slCmdLine << "-D";
		
	// Run a new process
	if (!Frontend::run("cscope", slCmdLine, s_sProjPath)) {
		emit aborted();
		return false;
	}

	return true;
}

/**
 * Executes a grep query.
 * A query is composed of a numeric type and a query text, which are written
 * to the stndard input of the currently running grep process.
 * @param	nType		The type of query to run
 * @param	sText		The query's text
 * @param	bCase		true for case-sensitive queries, false otherwise
 * @param	nMaxRecords	The maximal number of records to return (abort if this
 *						number is exceeded)
 */
void GrepFrontend::query(uint nType, const QString& sText, bool bCase, 
	uint nMaxRecords)
{
	QString sQuery;
	QStringList slArgs;
	
	m_nMaxRecords = nMaxRecords;
	
	// Create the grep command line
	slArgs.append(QString("-L") + QString::number(nType));
	slArgs.append(sText);
	slArgs.append("-d");
	if (!bCase)
		slArgs.append("-C");
		
	run(slArgs);
	
	// Initialise stdout parsing
	m_state = SearchSymbol;
	m_delim = WSpace;

	emit progress(0, 1);
}

/**
 * Rebuilds the symbol database of the current project.
 */
void GrepFrontend::rebuild()
{
	QStringList slArgs;
	
	// If a process is already running, kill it start a new one
	/*
	if (isRunning()) {
		m_bRebuildOnExit = true;
		kill();
		return;
	}
	*/
	
	// Run the database building process
	slArgs.append("-b");
	run(slArgs);
	
	// Initialise output parsing
	m_state = BuildStart;
	m_delim = Newline;
	
	emit progress(0, 1);
}

/**
 * Sets default parameters for all GrepFrontend projects based on the
 * current project.
 * @param	sProjPath	The full path of the project's directory
 * @param	nArgs		Project-specific command-line arguments
 */
void GrepFrontend::init(const QString& sProjPath, uint nArgs)
{
	s_sProjPath = sProjPath;
	s_nProjArgs = nArgs;
}

/**
 * Stops a grep action.
 */
void GrepFrontend::slotCancel()
{
	kill();
}

/**
 * Handles grep messages sent to the standard error stream.
 * @param	sText	The error message text
 */
void GrepFrontend::parseStderr(const QString& sText)
{
	// Wait for a complete line to arrive
	m_sErrMsg += sText;
	if (!sText.endsWith("\n"))
		return;
	
	// Display the error message
	emit error(m_sErrMsg);
		
	// Line displayed, reset the text accumulator
	m_sErrMsg = "";
}

/**
 * Called when the underlying process exits.
 * Checks if the rebuild flag was raised, and if so restarts the building
 * process.
 */
void GrepFrontend::finalize()
{
	// Reset the parser state machine
	m_state = Unknown;
	
	// Restart the building process, if required
	if (m_bRebuildOnExit) {
		m_bRebuildOnExit = false;
		rebuild();
	}
}

/**
 * Parses the output of a Cscope process.
 * Implements a state machine, where states correspond to the output of the
 * controlled Cscope process.
 * @param	sToken	The current token read (the token delimiter is determined
 *					by the current state)
 * @return	A value indicating the way this token should be treated: dropped,
 *			added to the token queue, or finishes a new record
 */
Frontend::ParseResult CscopeFrontend::parseStdout(QString& sToken,
	ParserDelim /* ignored */)
{
	int nFiles, nTotal, nRecords;
	ParseResult result = DiscardToken;
	ParserState stPrev;
	
	// Remember previous state
	stPrev = m_state;
	
	// Handle the token according to the current state
	switch (m_state) {
	case BuildStart:
		if (sToken == "Building cross-reference...") {
			m_state = BuildSymbol;
			m_delim = WSpace;
		}
		else if (sToken == "Building inverted index...") {
			emit buildInvIndex();
		}
		
		result = DiscardToken;
		break;

	case BuildSymbol:
		// A single angle bracket is the prefix of a progress indication,
		// while double brackets is Cscope's prompt for a new query
		if (sToken == ">") {
			m_state = Building;
			m_delim = Newline;
		}

		result = DiscardToken;
		break;

	case Building:
		// Try to get building progress
		if (sscanf(sToken.latin1(), BUILD_STR, &nFiles, &nTotal) == 2) {
			emit progress(nFiles, nTotal);
			
			// Check for last progress message
			if (nFiles == nTotal) {
				m_state = BuildStart;
				m_delim = Newline;
				
				result = DiscardToken;
				break;
			}
		}

		// Wait for another progress line or the "ready" symbol
		m_state = BuildSymbol;
		m_delim = WSpace;

		result = DiscardToken;
		break;

	case SearchSymbol:
		// Check for more search progress, or the end of the search,
		// designated by a line in the format of "cscope: X lines"
		if (sToken == ">") {
			m_state = Searching;
			m_delim = Newline;
			result = DiscardToken;
			break;
		}
		else if (sToken == "cscope:") {
			m_state = SearchEnd;
			m_delim = Newline;
			result = DiscardToken;
			break;
		}

	case File:
		// Is this the first entry? If so, signal that the query is complete
		if (stPrev != LineText)
			emit progress(1, 1);

		// Treat the token as the name of the file in this record
		m_state = Func;
		result = AcceptToken;
		break;

	case Searching:
		// Try to get the search progress value (ignore other messages)
		if ((sscanf(sToken.latin1(), SEARCH_STR, &nFiles, &nTotal) == 2) ||
			(sscanf(sToken.latin1(), INV_STR, &nFiles, &nTotal) == 2) ||
			(sscanf(sToken.latin1(), REGEXP_STR, &nFiles, &nTotal) == 2)) {
			emit progress(nFiles, nTotal);
		}

		m_state = SearchSymbol;
		m_delim = WSpace;
		result = DiscardToken;
		break;

	case SearchEnd:
		// Get the number of results found in this search
		if ((sscanf(sToken.latin1(), SEARCHEND_STR, &nRecords) == 1) &&
			(m_nMaxRecords > 0) &&
			(nRecords > m_nMaxRecords)) {
			result = Abort;
		}
		else {
			m_state = File;
			m_delim = WSpace;
			result = DiscardToken;
		}
		
		break;
		
	case Func:
		// Treat the token as the name of the function in this record
		if (sToken.toInt()) {
			// In case of a global definition, there is no function name, and
			// instead the line number is given immediately
			m_state = LineText;
			m_delim = Newline;
		}
		else {
			// Not a number, it is the name of the function
			m_state = Line;
		}
		
		result = AcceptToken;
		break;

	case Line:
		// Treat the token as the line number in this record
		m_state = LineText;
		m_delim = Newline;
		result = AcceptToken;
		break;

	case LineText:
		// Treat the token as the text of this record, and report a new
		// record
		m_state = File;
		m_delim = WSpace;
		result = RecordReady;
		break;

	default:
		// Do nothing (prevents a compilation warning for unused enum values)
		break;
	}

	return result;
}

// Sun Sep 25 16:40:41 PDT 2011
