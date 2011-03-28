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

#include "cscopefrontend4.h"
#include "editormanager4.h"
#include "kscope4.h"

KScope::KScope(QWidget *){
	KTextEditor::Editor *editor = KTextEditor::EditorChooser::editor();
	m_doc = editor->createDocument(0);
   	m_view = qobject_cast<KTextEditor::View*>(m_doc->createView(this));
	setCentralWidget(m_view);

	setupActions();

	// Create the initial GUI (no active part)
	setXMLFile("kscopeui.rc");
	createShellGUI();
	guiFactory()->addClient(m_view);

	// Create all child widgets
	initMainWindow();

	// Create control objects
	// m_pProjMgr = new ProjectManager();
	// m_pEditMgr = new EditorManager(this);
	// m_pCallTreeMgr = new CallTreeManager(this);
}

void KScope::setupActions()
{
	KStandardAction::open(this, SLOT(openFile()), actionCollection());
}

void KScope::openFile()
{
	m_view->document()->openUrl(KFileDialog::getOpenFileName());	
}

/**
 * Starts a shell script to ensure that Cscope is properly installed and to
 * extract the supported command-line arguments. 
 */
void KScope::verifyCscope()
{
	statusBar()->showMessage(i18n("Verifying Cscope installation..."), 0);
	CscopeVerifier* pVer;
	pVer = new CscopeVerifier();

	// connect(pVer, SIGNAL(done(bool, uint)), this,
	//	SLOT(slotCscopeVerified(bool, uint)));

	pVer->verify();
}

void KScope::initMainWindow()
{
	KStatusBar* pStatus;

	// Create the status bar
	pStatus = statusBar();
	pStatus->insertItem(i18n(" Line: N/A Col: N/A "), 0, 0);

	return;
}

// Sat Mar 19 23:50:42 UTC 2011
