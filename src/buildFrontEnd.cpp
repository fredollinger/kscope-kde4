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

bool buildFrontEnd::build(QString s_sProjPath) 
{
	qDebug ()<< "buildFrontEnd::build(): "<< s_sProjPath;

	QStringList slCmdLine;

	// QString s_sProjPath = "."; // FIXME: put in project path

	setOutputChannelMode(KProcess::MergedChannels);

	connect(this, SIGNAL(readyRead()),
	this, SLOT(slotDisplayResults()));
	
	// Run a new process
	if (!Frontend::run("make", slCmdLine, s_sProjPath)) {
		emit aborted();
		return false;
	}
	return true;
}


bool buildFrontEnd::slotDisplayResults(){
	qDebug() << "buildFrontEnd::slotDisplayResults()";
	disconnect(this, SIGNAL(readyRead()), 0, 0);

	setReadChannel(QProcess::StandardOutput);
	QString qs;
	QByteArray qba;
	while (atEnd() == false){
		qba = readLine(2000);	
		qs = qs + QString(qba);
	}
	
	qDebug() << qs;

//	m_qmbMsg->setText(qs);
	//m_qmbMsg->exec();

	return true;
}

} // namespace kscope4
// Thu Oct 27 18:00:16 PDT 2011
