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

	connect(pushButtonLs, SIGNAL(clicked()),
	this, SLOT(slotLs()));
}

KmvcDlg::~KmvcDlg()
{

}

void KmvcDlg::slotLs()
{
	qDebug() << "ls \n";
}

// Sun Sep 25 09:51:16 PDT 2011
