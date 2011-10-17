/*
 * Copyright (C) 2011 Fred Ollinger (follinge@gmail.com)
 *
 * Frontend to the version control systems.
 * The name of each function is from git, but we run analogous commands for other systems.
 * For example, commit() called "submit" for p4 as there's no "p4 commit".
 *
 */
#include <qdebug.h>

#include <qstringlist.h>
#include <qprogressbar.h>
#include <qlabel.h>
#include "frontend4.h"

#include "vcsFrontEnd.h"

namespace kscope4{
vcsFrontEnd::vcsFrontEnd(bool bAutoDelete) : 
	Frontend(CSCOPE_RECORD_SIZE, bAutoDelete),
	m_state(vcsUnknown),
	m_sErrMsg(""),
	m_bRebuildOnExit(false)
{
}

vcsFrontEnd::~vcsFrontEnd() 
{
}

bool vcsFrontEnd::commit(QString msg){
	qDebug() << "commit\n";

	QStringList slCmdLine;

	QString s_sProjPath = "."; // FIXME: put in project path

	slCmdLine << "-a";

	slCmdLine << "-m '"; 
	slCmdLine << msg;
	slCmdLine << "'";

	// FIXME:Branch based upon command, that is p4, etc
		
	// Run a new process
	//if (!Frontend::run("git", slCmdLine, s_sProjPath)) {
	Frontend::run("git", slCmdLine, s_sProjPath);

	// FIXME: we need to return false if command fails...
	return true;
}

} // namespace kscope4
// Sun Oct 16 18:07:49 PDT 2011
