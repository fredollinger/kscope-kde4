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
#include "kscope4-common.h"
#include "kscopeconfig4.h"

namespace kscope4{
vcsFrontEnd::vcsFrontEnd() : 
	Frontend(CSCOPE_RECORD_SIZE, false),
	m_state(vcsUnknown),
	m_sErrMsg(""),
	m_bRebuildOnExit(false)
{
	m_qmbMsg = new QMessageBox();
}

vcsFrontEnd::~vcsFrontEnd() 
{
}

/**
 * Pushes the all ready committed changes to the server. 
 * At this time, does nothing if we are using p4.
 * @return	true if successful, false otherwise
*/

bool vcsFrontEnd::push(QString rootdir){
	QStringList slCmdLine;
	QString cmd;

	setOutputChannelMode(KProcess::MergedChannels);
	
	const QString s_sProjPath = Config().lastOpenProject();
	
	if (VCS_GIT == Config().vcs()){
		slCmdLine << "push";
		cmd = "git"; 
	}
	else{
		qDebug() << "there is no version of push for this vcs!!";
		return true;
	}

	connect(this, SIGNAL(readyRead()),
	this, SLOT(slotDisplayResults()));
		
	// Run a new process

	if (!Frontend::run("git", slCmdLine, s_sProjPath)) {
		emit aborted();
		return false;
	}
	
	return true;
}

bool vcsFrontEnd::slotDisplayResults(){
	disconnect(this, SIGNAL(readyRead()), 0, 0);

	setReadChannel(QProcess::StandardOutput);
	QString qs;
	QByteArray qba;
	while (atEnd() == false){
		qba = readLine(2000);	
		qs = qs + QString(qba);
	}

	m_qmbMsg->setText(qs);
	m_qmbMsg->exec();

	return true;
}

/* Writes a commit message. Whether things get pushed to mother ship depend up on the 
 * type of vcs. For example, p4 pushes things automatically while git does not.
 * We may want to make this changable by a flag or even just push everything upon commit.
 * Not sure yet.
 */
bool vcsFrontEnd::commit(QString s_sProjPath, QString msg){
	QStringList slCmdLine;
	QString cmd;

	QString fmsg = "\""; //msg which is fixed with quotes
	fmsg.append(msg);
	fmsg.append("\"");

	// BEGIN git
	if (VCS_GIT == Config().vcs()){
		slCmdLine << "commit";
		slCmdLine << "-a";
		slCmdLine << "-m"; 
		slCmdLine << fmsg;
		cmd = "git";
	}
	// END git
	else if (VCS_P4 == Config().vcs()){
		slCmdLine << "submit";
		slCmdLine << "-m"; 
		slCmdLine << fmsg;
		cmd = "p4";
	}
	else{
		qDebug() << "No vcs!!";
	}

	// FIXME:Branch based upon command, that is p4, etc
		
	// Run a new process
	//if (!Frontend::run("git", slCmdLine, s_sProjPath)) {
	Frontend::run(cmd, slCmdLine, s_sProjPath);

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

bool vcsFrontEnd::diff(){

	QStringList slCmdLine;

	const QString s_sProjPath = Config().lastOpenProject();

	setOutputChannelMode(KProcess::MergedChannels);
	
	slCmdLine << "--no-pager";
	slCmdLine << "diff";
	slCmdLine << "HEAD";

	// Run a new process
	if (!Frontend::run("git", slCmdLine, s_sProjPath)) {
		emit aborted();
		return false;
	}
	
	return true;
}

bool vcsFrontEnd::pull(){
	QStringList slCmdLine;

	connect(this, SIGNAL(readyRead()),
	this, SLOT(slotDisplayResults()));

	setOutputChannelMode(KProcess::MergedChannels);
	
	const QString s_sProjPath = Config().lastOpenProject();

	slCmdLine << "pull";

	// Run a new process
	if (!Frontend::run("git", slCmdLine, s_sProjPath)) {
		emit aborted();
		return false;
	}
	
	return true;
}

} // namespace kscope4
// Sat Oct 29 09:12:36 PDT 2011
