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

bool vcsFrontEnd::push(){
	qDebug ()<< "vcsFrontEnd::push()";

	setOutputChannelMode(KProcess::MergedChannels);

	QStringList slCmdLine;
	QString s_sProjPath = "."; // FIXME: put in project path
	//slCmdLine << "push"; 

	connect(this, SIGNAL(finished(uint)), this,
		SLOT(slotPushDone(uint)));

	Frontend::run("ls", slCmdLine, s_sProjPath);

	waitForFinished();

	qDebug ()<< "vcsFrontEnd::done()";
	return true;
}

#if 0
void KmvcDlg::slotLsDone(uint ui){
	qDebug() << "slotLsDone(): " << m_gfe->bytesAvailable();
	m_gfe->setReadChannel(QProcess::StandardOutput);
	QString qs;
	QByteArray qba;
	qDebug() << "slotLsDone(): " << m_gfe->bytesAvailable();
	while (m_gfe->atEnd() == false){
		qba = m_gfe->readLine(2000);	
		qs = QString(qba);
		m_list << qs;
		qDebug() << qs;
	}

     	// m_list << "a" << "b" << "c";
     	m_model->setStringList(m_list);
	qDebug() << "slotLsDone(): DONE " << m_list.size();
}
#endif

bool vcsFrontEnd::slotPushDone(uint i){
	qDebug ()<< "vcsFrontEnd::slotPushDone()";
	// FIXME: Disconnect slot

	setReadChannel(QProcess::StandardOutput);
	QString qs;
	QByteArray qba;
	qDebug() << "slotLsDone(): " << bytesAvailable();
	while (atEnd() == false){
		qba = readLine(2000);	
		qs = QString(qba);
		qDebug() << qs;
	}


	return true;
}

/* Writes a commit message. Whether things get pushed to mother ship depend up on the 
 * type of vcs. For example, p4 pushes things automatically while git does not.
 * We may want to make this changable by a flag or even just push everything upon commit.
 * Not sure yet.
 */
bool vcsFrontEnd::commit(QString msg){
	QStringList slCmdLine;

	QString fmsg = "\""; //msg which is fixed with quotes
	fmsg.append(msg);
	fmsg.append("\"");

	QString s_sProjPath = "."; // FIXME: put in project path

	slCmdLine << "-a";

	slCmdLine << "-m"; 
	slCmdLine << fmsg;

	// FIXME:Branch based upon command, that is p4, etc
		
	// Run a new process
	//if (!Frontend::run("git", slCmdLine, s_sProjPath)) {
	Frontend::run("git", slCmdLine, s_sProjPath);

	// FIXME: we need to return false if command fails...
	return true;
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
Frontend::ParseResult vcsFrontEnd::parseStdout(QString& sToken,
	ParserDelim /* ignored */)
{
	int nFiles, nTotal, nRecords;
	ParseResult result = DiscardToken;
	
	return result;
}

} // namespace kscope4
// Sat Oct 22 13:39:30 PDT 2011
