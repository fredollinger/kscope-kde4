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

#include "buildFrontEnd.h"

namespace kscope4{
buildFrontEnd::buildFrontEnd() : 
	Frontend(CSCOPE_RECORD_SIZE, false),
	m_sErrMsg(""),
	m_bRebuildOnExit(false)
{
}

buildFrontEnd::~buildFrontEnd() 
{
}


/**
 * FIXME: NOW THIS IS ONLY A STUB TO SHUT UP COMPILER!
 * Parses the output of a vcs process.
 * Implements a state machine, where states correspond to the output of the
 * controlled vcs process.
 * @param	sToken	The current token read (the token delimiter is determined
 *					by the current state)
 * @return	A value indicating the way this token should be treated: dropped,
 *			added to the token queue, or finishes a new record
 */
Frontend::ParseResult buildFrontEnd::parseStdout(QString& sToken,
	ParserDelim /* ignored */)
{
	int nFiles, nTotal, nRecords;
	ParseResult result = DiscardToken;
	
	return result;
}

bool buildFrontEnd::build() 
{
	qDebug ()<< "buildFrontEnd::build()";
	return true;
}

} // namespace kscope4
// Thu Oct 27 18:00:16 PDT 2011
