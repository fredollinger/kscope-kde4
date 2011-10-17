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
vcsFrontEnd::vcsFrontEnd() : 
	Frontend(CSCOPE_RECORD_SIZE, false),
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

/**
 * Parses the output of a vcs process.
 * Implements a state machine, where states correspond to the output of the
 * controlled vcs process.
 * @param	sToken	The current token read (the token delimiter is determined
 *					by the current state)
 * @return	A value indicating the way this token should be treated: dropped,
 *			added to the token queue, or finishes a new record
 */
Frontend::ParseResult vcsFrontEnd::parseStdout(QString& sToken,
	ParserDelim /* ignored */)
{
	int nFiles, nTotal, nRecords;
	ParseResult result = DiscardToken;
	
	return result;
}

} // namespace kscope4
// Sun Oct 16 18:07:49 PDT 2011
