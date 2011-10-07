#include <qdebug.h>

#include <QMainWindow>

#include "KmvcDlg.h"
#include "grepfrontend.h"

KmvcDlg::KmvcDlg(QWidget* pParent, const char* szName) :
	m_gfe(NULL)
{
 	m_model = new QStringListModel();
     	m_list << "a" << "b" << "c";
     	m_model->setStringList(m_list);
	
	setupUi(this);

	// listView->setModel(m_model);

	// Create a persistent grep process
	m_gfe = new GrepFrontend(false);

	connect(pushButtonLs, SIGNAL(clicked()),
	this, SLOT(slotLs()));
}

KmvcDlg::~KmvcDlg()
{

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
	qDebug() << "slotLsDone(): " << ui;
	QByteArray qba;
	QString qs;
	qDebug() << m_gfe->bytesAvailable();
	while (m_gfe->atEnd() == false){
		qba = m_gfe->readLine(2000);	
		qs = QString(qba);
		qDebug() << qs;
	}
	qDebug() << "slotLsDone(): DONE " << ui;
}

// Sun Sep 25 09:51:16 PDT 2011
