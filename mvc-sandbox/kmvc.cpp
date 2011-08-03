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

<<<<<<< HEAD
#include "kmvc.h"

namespace kmvc{
kmvc::kmvc(QWidget *) 
	// m_pProgressDlg(NULL)
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
	// m_pEditMgr = new EditorManager(this);
	// m_pCallTreeMgr = new CallTreeManager(this);
	m_pFileView = new FileView(this);


	// BEGIN STUFF FROM KSCOPE
	// Connect menu and toolbar items with the object's slots
	// m_pActions = new KScopeActions(this);
	// m_pActions->init();
	//m_pActions->slotEnableProjectActions(false);
	// END STUFF FROM KSCOPE
	*/
	return;
=======
namespace kmvc{
kmvc::kmvc(QWidget *)
{
	m_view = new QStringListModel();
	setCentralWidget(m_view);
	// initMainWindow();
>>>>>>> 3ce318e587682508c5d46725347362b0ff043643
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

} // namespace kscope4
// Sat Jul 16 18:23:16 UTC 2011
=======
}
*/

void kmvc::setupActions()
{
}

void kmvc::initMainWindow()
{
	KStatusBar* pStatus;

	// Create the status bar
	pStatus = statusBar();
	pStatus->insertItem(i18n(" Line: N/A Col: N/A "), 0, 0);

	return;
}
} // namespace kmvc

// Sun Jul 31 08:48:30 PDT 2011
>>>>>>> 3ce318e587682508c5d46725347362b0ff043643
