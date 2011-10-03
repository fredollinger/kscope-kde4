#ifndef GREPFRONTEND_H
#define GREPFRONTEND_H

#include <qstringlist.h>
#include <qprogressbar.h>
#include <qlabel.h>
#include "frontend4.h"

#define CSCOPE_RECORD_SIZE 4

/**
 * Controls a grep process for the current project.
 * This class creates a grep process, using the project's files for
 * configuration. Once the process is running, KScope uses the query() method
 * to initiate grep queries on the project's files. The queries' output is
 * parsed into a set of records, each consisting of the following fields:
 * - File name
 * - Function name
 * - Line number
 * - The line's text
 * These records are used to display the output in different windows, such as
 * QueryWidget and CallTreeDlg.
 * @author Elad Lahav
 */

class GrepFrontend : public Frontend
{
	Q_OBJECT

public:
	GrepFrontend(bool bAutoDelete = false);
	~GrepFrontend();

	/**
	 * The available Grep query types.
	 */
	enum QueryType { Reference = 0, Definition = 1, Called = 2, Calling = 3,
		Text = 4, Pattern = 6, FileName = 7, Including = 8, None = 9 };

	/**
	 * Options for running Grep, used to construct the command line.
	 * Some of these options are global, while some are project specific.
	 */
	enum Options { VerboseOut = 0x01, SlowPathDef = 0x02,
		Kernel = 0x04, InvIndex = 0x08, NoCompression = 0x10 };

	void query(uint, const QString&, bool bCase = true, uint nMaxRecords = 0);
	void rebuild();
	
	static void init(const QString&, uint);
	
	/**
	 * @param	nArgs	The command-line arguments supported by the version of
	 *					Grep currently in use
	 */
	static void setSupArgs(uint nArgs) { s_nSupArgs = nArgs; }

	/** Project-specific options for the command-line arguments. */
	static uint s_nProjArgs;
	
public slots:
	void slotCancel();
	void slotFinished();

signals:
	/**
	 * Emitted when Grep starts building the inverted index.
	 */
	void buildInvIndex();
	void done(bool, uint);

protected:
	virtual ParseResult parseStdout(QString&, ParserDelim);
	virtual void parseStderr(const QString&);
	virtual void finalize();

private:
	/**
	 * The possible states of the parser state machine.
	 */
	enum ParserState { Unknown = 0, BuildStart, BuildSymbol, Building,
		SearchSymbol, Searching, SearchEnd, File, Func, Line, LineText };

	bool m_bResult;
	uint m_nArgs;
	
	/** The current state of the parser state machine. */
	ParserState m_state;
	
	/** Accumulates text sent by Grep to the standard error stream. */
	QString m_sErrMsg;
	
	/** If true, the rebuild process will be restarted when the process
		exits. */
	bool m_bRebuildOnExit;
	
	/** The maximal number of records requested for the current query.
		The process aborts if this number if reached. */
	int m_nMaxRecords;
	
	/** The full path of the directory holding the project files. */
	static QString s_sProjPath;
	
	/** The command line arguments supported by this version of Grep. */
	static uint s_nSupArgs;
	
	bool run(const QStringList&);

};

#endif
