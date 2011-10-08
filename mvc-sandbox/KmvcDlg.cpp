#include <qdebug.h>

#include <QMainWindow>

#include "KmvcDlg.h"
#include "grepfrontend.h"

KmvcDlg::KmvcDlg(QWidget* pParent, const char* szName) :
	m_gfe(NULL)
{
 	m_model = new QStringListModel();
     	// m_list << "a" << "b" << "c";
     	m_model->setStringList(m_list);

	setupUi(this);

	listView->setModel(m_model);

	// Create a persistent grep process
	m_gfe = new GrepFrontend(false);

	connect(pushButtonLs, SIGNAL(clicked()),
	this, SLOT(slotLs()));

	connect(m_gfe, SIGNAL(readyRead()),
	this, SLOT(slotReadStd()));

	connect(m_gfe, SIGNAL(started()),
	this, SLOT(slotStarted()));
}

KmvcDlg::~KmvcDlg()
{

}

void KmvcDlg::slotStarted(){
	qDebug() << "slotStarted() \n";
}

void KmvcDlg::slotReadStd()
{
	qDebug() << "slotReadStd() \n";
}

void KmvcDlg::slotLs()
{
	qDebug() << "slotLs() \n";
	connect(m_gfe, SIGNAL(finished(uint)), this,
		SLOT(slotLsDone(uint)));

	QStringList qsl;

	m_gfe->run(qsl);
}

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

// Fri Oct  7 14:00:55 PDT 2011
