
/*
 * Copyright (C) 2011 Fred Ollinger (follinge@gmail.com)
 *
 * Frontend to the version control systems.
 * The name of each function is from git, but we run analogous commands for other systems.
 * For example, commit() called "submit" for p4 as there's no "p4 commit".
 *
 */

#ifndef VCS_FRONT_END_H
#define VCS_FRONT_END_H

#include <qstringlist.h>
#include <qprogressbar.h>
#include <qlabel.h>
#include <QMessageBox>
#include "frontend4.h"

namespace kscope4{

#define CSCOPE_RECORD_SIZE 4

enum VcsState { vcsUnknown = 0, vcsGit, vcsP4 };

class vcsFrontEnd : public Frontend
{
	Q_OBJECT

public:
	vcsFrontEnd();
	~vcsFrontEnd();
	bool commit(QString); // also called submit in the p4 world
	bool push(); // send files to server (no p4 equivalent)
	bool diff(); // diff of current changes and last commit

protected:
	virtual ParseResult parseStdout(QString&, ParserDelim);
private:
	QMessageBox *m_qmbMsg; // message box dialog
	/** The current state of the parser state machine. */
	VcsState m_state;

	bool m_bResult;
	uint m_nArgs;
	
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

private slots:
	bool slotPushDone();
};

} // namespace kscope4
#endif
// Wed Oct 26 18:22:32 PDT 2011
