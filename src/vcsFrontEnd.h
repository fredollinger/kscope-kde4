
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
#include "frontend4.h"

namespace kscope4{

#define CSCOPE_RECORD_SIZE 4

enum VcsState { vcsUnknown = 0, vcsGit, vcsP4 };

class vcsFrontEnd : public Frontend
{
	Q_OBJECT

public:
	vcsFrontEnd(bool bAutoDelete = false);
	~vcsFrontEnd();
	bool commit(QString); // also called submit in the p4 world
private:
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
};

} // namespace kscope4
#endif
// Sat Oct 15 17:52:05 PDT 2011
