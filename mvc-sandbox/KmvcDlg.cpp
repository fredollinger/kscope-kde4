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

	// Create a persistent Cscope process
	m_gfe = new GrepFrontend();

	connect(pushButtonLs, SIGNAL(clicked()),
	this, SLOT(slotLs()));
}

KmvcDlg::~KmvcDlg()
{

}

void KmvcDlg::slotLs()
{
	qDebug() << "slotLs() \n";
	connect(m_gfe, SIGNAL(done(bool, uint)), this,
		SLOT(slotLsDone(bool, uint)));

	QStringList qsl;

	m_gfe->run(qsl);
}

void KmvcDlg::slotLsDone(bool b, uint i){
	qDebug() << "slotLsDone() \n";
}

// Sun Sep 25 09:51:16 PDT 2011
