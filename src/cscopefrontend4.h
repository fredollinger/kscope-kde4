#ifndef CSCOPEFRONTEND_H
#define CSCOPEFRONTEND_H

#include <qstringlist.h>
#include <qprogressbar.h>
#include <qlabel.h>
#include "frontend4.h"

#define CSCOPE_RECORD_SIZE 4

/**
 * Controls a Cscope process for the current project.
 * This class creates a Cscope process, using the project's files for
 * configuration. Once the process is running, KScope uses the query() method
 * to initiate Cscope queries on the project's files. The queries' output is
 * parsed into a set of records, each consisting of the following fields:
 * - File name
 * - Function name
 * - Line number
 * - The line's text
 * These records are used to display the output in different windows, such as
 * QueryWidget and CallTreeDlg.
 * @author Elad Lahav
 */

class CscopeFrontend : public Frontend
{
	Q_OBJECT

public:
	CscopeFrontend(bool bAutoDelete = false);
	~CscopeFrontend();

	/**
	 * The available Cscope query types.
	 */
	enum QueryType { Reference = 0, Definition = 1, Called = 2, Calling = 3,
		Text = 4, Pattern = 6, FileName = 7, Including = 8, None = 9 };

	/**
	 * Options for running Cscope, used to construct the command line.
	 * Some of these options are global, while some are project specific.
	 */
	enum Options { VerboseOut = 0x01, SlowPathDef = 0x02,
		Kernel = 0x04, InvIndex = 0x08, NoCompression = 0x10 };

	void query(uint, const QString&, bool bCase = true, uint nMaxRecords = 0);
	void rebuild();
	
	static void init(const QString&, uint);
	
	/**
	 * @param	nArgs	The command-line arguments supported by the version of
	 *					Cscope currently in use
	 */
	static void setSupArgs(uint nArgs) { s_nSupArgs = nArgs; }
	
public slots:
	void slotCancel();

signals:
	/**
	 * Emitted when Cscope starts building the inverted index.
	 */
	void buildInvIndex();

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
	
	/** The current state of the parser state machine. */
	ParserState m_state;
	
	/** Accumulates text sent by Cscope to the standard error stream. */
	QString m_sErrMsg;
	
	/** If true, the rebuild process will be restarted when the process
		exits. */
	bool m_bRebuildOnExit;
	
	/** The maximal number of records requested for the current query.
		The process aborts if this number if reached. */
	int m_nMaxRecords;
	
	/** The full path of the directory holding the project files. */
	static QString s_sProjPath;
	
	/** Project-specific options for the command-line arguments. */
	static uint s_nProjArgs;
	
	/** The command line arguments supported by this version of Cscope. */
	static uint s_nSupArgs;
	
	bool run(const QStringList&);
};

/**
 * Provides progress information on a Cscope query.
 * Classes used to display query results can use this class to show a
 * progress bar while a query is running, and a "Please Wait..." label while
 * output is being processed.
 * @author Elad Lahav
 */
class CscopeProgress : public QObject
{
	Q_OBJECT

public:
	CscopeProgress(QWidget*);
	~CscopeProgress();
	
	void setProgress(int, int);
	void finished();
	
private:
	/** The parent widget for the progress bar and label. */
	QWidget* m_pMainWidget;
	
	/** A bar used to display query progress information. */
	QProgressBar* m_pProgressBar;
	
	/** A label used to display a "Please wait..." message. */
	QLabel* m_pLabel;
	
private slots:
	void slotShowProgressBar();
	void slotShowLabel();
};

class CscopeVerifier : public QObject
{
	Q_OBJECT
	
public:
	CscopeVerifier() : m_bResult(false), m_nArgs(0) {}
	
	void verify();
	
signals:
	void done(bool, uint);
	
private:
	bool m_bResult;
	uint m_nArgs;
	
private slots:
	void slotConfigResult(uint, const QString&);
	void slotFinished();
};

#endif
