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
#include "kmvc.h"
#include <QStringList>
#include <QStringListModel>

#include "kmvc.h"

namespace kmvc{
kmvc::kmvc(QWidget *) 
{

	/*
	KTextEditor::Editor *editor = KTextEditor::EditorChooser::editor();
	m_doc = editor->createDocument(0);
   	m_view = qobject_cast<KTextEditor::View*>(m_doc->createView(this));
	setCentralWidget(m_view);

	setupActions();

	// Create the initial GUI (no active part)
	
	createShellGUI();
	guiFactory()->addClient(m_view);

	// Create all child widgets
	initMainWindow();

	// Create control objects
	m_pProjMgr = new ProjectManager();

	// BEGIN STUFF FROM KSCOPE
	// Connect menu and toolbar items with the object's slots
	// m_pActions = new KScopeActions(this);
	// m_pActions->init();
	//m_pActions->slotEnableProjectActions(false);
	// END STUFF FROM KSCOPE
	*/
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
	KStatusBar* pStatus;

	// Create the status bar
	// pStatus = statusBar();
	// pStatus->insertItem(i18n(" Line: N/A Col: N/A "), 0, 0);

	return;
}

} // namespace kmvc

// Fri Aug  5 11:13:49 PDT 2011
