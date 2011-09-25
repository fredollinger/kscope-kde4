#include <qdebug.h>

#include <QMainWindow>

#include "KmvcDlg.h"

KmvcDlg::KmvcDlg(QWidget* pParent, const char* szName) 
{
 	m_model = new QStringListModel();
     	m_list << "a" << "b" << "c";
     	m_model->setStringList(m_list);
	

	setupUi(this);

	listView->setModel(m_model);
}

KmvcDlg::~KmvcDlg()
{
}

// Sun Sep 25 09:51:16 PDT 2011
