#include <kparts/part.h>
#include <KStandardAction>
#include <KActionCollection>
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>
#include <KXMLGUIFactory>
#include <KFileDialog>
#include <KStatusBar>
#include <KMessageBox>
#include <qdebug.h>
#include <QStringList>
#include <QListWidget>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QPushButton>
#include <kvbox.h>
#include <QListView>

#include "kmvc.h"

namespace kmvc{
kmvc::kmvc(QWidget *) 
{
  m_vbox = new KVBox( this );

  setCentralWidget(m_vbox);

  m_model = new QStringListModel(m_vbox);

  // QPushButton *but = new QPushButton(m_vbox);
  list << "a" << "b" << "c";
  m_model->insertRows(m_model->rowCount(), 1);

  m_model->setStringList(list);

  m_view = new QListView( this );
  m_view->setModel(m_model);

  m_view->show();

  // qDebug() << m_model->rowCount();

  return;
}

/**
 * Class destructor.
 */
/*
kmvc::~KMVC()
{
<<<<<<< HEAD
	// Save configuration
	// Config().store();
	// Config().storeWorkspace(this);
	
	delete m_pProjMgr;
	delete m_pCallTreeMgr;
	delete m_pEditMgr;
	delete m_pCscopeBuild;
	
	if (m_pMakeDlg != NULL)
		delete m_pMakeDlg;
}
	*/

void kmvc::setupActions()
{
}

void kmvc::initMainWindow()
{
	// KStatusBar* pStatus;

	// Create the status bar
	// pStatus = statusBar();
	// pStatus->insertItem(i18n(" Line: N/A Col: N/A "), 0, 0);

	return;
}

} // namespace kmvc

// Fri Aug  5 11:13:49 PDT 2011
