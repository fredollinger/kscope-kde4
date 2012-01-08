#include <qfile.h>
#include <klocale.h>
#include "querypage4.h"
#include "queryview4.h"
// #include "queryviewdriver4.h"

namespace kscope4{
const char* QUERY_TYPES[][2] = {
	{ "References to ", "REF " },
	{ "Definition of ", "DEF " },
	{ "Functions called by ", "<-- " },
	{ "Functions calling ", "-->" },
	{ "Search for ", "TXT " },
	{ "", "" },
	{ "EGrep Search for ", "GRP " },
	{ "Files named ", "FIL " },
	{ "Files #including ", "INC " },
	{ "Query", "Query" }
};

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
QueryPage::QueryPage(QWidget* pParent, const char * szName) :
	QueryPageBase(),
	m_nType(CscopeFrontend::None)
{
	m_pView = new QueryView(this, szName);
	// m_pDriver = new QueryViewDriver(m_pView, this);
	
	// connect(m_pView, SIGNAL(lineRequested(const QString&, uint)), this,
	//	 SIGNAL(lineRequested(const QString&, uint)));
	
	// Set colours and font
	// applyPrefs();
}

/**
 * Class destructor.
 */
QueryPage::~QueryPage()
{
}

/**
 * Runs a query, using the current page to display the results.
 * @param	nType	The type of the query
 * @param	sText	The text of the query
 * @param	bCase		true for case-sensitive queries, false otherwise
 */
void QueryPage::query(uint nType, const QString& sText, bool bCase)
{
	m_nType = nType;
	m_sText = sText;
	m_bCase = bCase;
	m_sName = getCaption();
	
	// m_pDriver->query(nType, sText, bCase);
}

/**
 * Re-runs the last query.
 */
void QueryPage::refresh()
{
	// m_pView->clear();
	// if (!m_sText.isEmpty())
		// m_pDriver->query(m_nType, m_sText, m_bCase);
}

/**
 * Resets the query page by deleting all records.
 */
void QueryPage::clear()
{
	// m_pView->clear();
	m_nType = CscopeFrontend::None;
	m_sText = QString();
	m_sName = QString();
}

/**
 * @return	true if a query is currently running in this page, false otherwise
 */
bool QueryPage::isRunning()
{
	// return m_pDriver->isRunning();
	return true;
}

/** 
 * Constructs a caption for this page, based on the query's type and text.
 * @param	bBrief	true to use a shortened version of the caption, false
 *					(default) for the full version
 * @return	The caption for this page
 */
QString QueryPage::getCaption(bool bBrief) const
{
	return QString(QUERY_TYPES[m_nType][bBrief ? 1 : 0] + m_sText);
}

/**
 * Creates a new query result item.
 * @param	sFile	The file name
 * @param	sFunc	The function defining the scope of the result
 * @param	sLine	The line number
 * @param	sText	The contents of the line
 */
void QueryPage::addRecord(const QString& sFile, const QString& sFunc,
	const QString& sLine, const QString& sText)
{
	// new QListViewItem(m_pView, sFile, sFunc, sLine, sText);
}

/**
 * Creates a unique file name for saving the contents of the query page.
 * @param	sProjPath	The full path of the project directory
 * @return	The unique file name to use
 */
QString QueryPage::getFileName(const QString& sProjPath) const
{
	QString sFileName, sFileNameBase;
	int i = 0;
	
	// Do nothing if not initialised
	if (m_sName.isEmpty())
		return "";
	
	// Create a unique file name
	sFileNameBase = m_sName;
	sFileNameBase.replace(' ', '_');
	do {
		sFileName = sFileNameBase + QString::number(++i);
	} while (QFile(sProjPath + "/" + sFileName).exists());
	
	return sFileName;
}

/**
 * Reads query parameters from a file.
 * This mehtod is used as part of the loading process.
 * @param	str	A text stream set to the correct place in the file
 * @return	true if successful, false otherwise
 */
bool QueryPage::readHeader(QTextStream& str)
{
	QString sTemp;
	
	/*
	// Read the query name
	m_sName = str.readLine();
	if (m_sName == QString::null || m_sName.isEmpty())
		return false;
		
	// Read the query's type
	sTemp = str.readLine();
	if (sTemp == QString::null || sTemp.isEmpty())
		return false;
	
	// Convert the type string to an integer
	m_nType = sTemp.toUInt();
	if (m_nType >= CscopeFrontend::None) {
		m_nType = CscopeFrontend::None;
		return false;
	}		
				
	// Read the query's text
	m_sText = str.readLine();
	if (m_sText == QString::null || m_sText.isEmpty())
		return false;
	*/

	return true;
}

/**
 * Writes query parameters to a file.
 * This mehtod is used as part of the storing process.
 * @param	str	A text stream set to the correct place in the file
 */
void QueryPage::writeHeader(QTextStream& str)
{
	// str << m_sName << "\n" << m_nType << "\n" << m_sText << "\n";
}
} // namespace kscope4

// Fri Sep  2 12:20:31 PDT 2011
