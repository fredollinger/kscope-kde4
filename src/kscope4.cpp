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

#include "cscopefrontend4.h"
#include "editormanager4.h"
#include "kscope4.h"

KScope::KScope(QWidget *) :
	m_bCscopeVerified(false),
	m_pProgressDlg(NULL)
{
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

/**
 * Reports the results of the Cscope verification script.
 * This slot is connected to the done() signal emitted by the CscopeVerifier
 * object constructed in verifyCscope().
 */
void KScope::slotCscopeVerified(bool bResult, uint nArgs)
{
	// statusBar()->message(i18n("Verifying Cscope installation...Done"), 3000);
	statusBar()->showMessage(i18n("Verifying Cscope installation...Done"),
3000);
	
	// Mark the flag even if Cscope was not found, to avoid nagging the user
	// (who may wish to use KScope even with Cscope disabled)
	m_bCscopeVerified = true;

	// Prompt the user in case Cscope is not properly installed
	if (!bResult) {
		KMessageBox::error(0, i18n("Cscope may not be properly installed on "
			"this system.\nPlease check the Cscope path specified in KScope's "
			"configuration dialogue."));
		slotConfigure();
		return;
	}
		
	// Set the discoverred supported command-line arguments
	// CscopeFrontend::setSupArgs(nArgs);
	
	// Build the database, if required
	/*
	if (m_bRebuildDB) {
		m_bRebuildDB = false;
		slotRebuildDB();
	}
	*/
}

/**
 * Handles the "Settings->Configure KScope..." command.
 * Displays the prferences dialog, which allows the user to set different
 * configuration parameters for KScope.
 */
void KScope::slotConfigure()
{
	/* 

	PreferencesDlg dlg;

	// Apply the preferences if either the "Apply" or the "OK" buttons are
	// clicked
	connect(&dlg, SIGNAL(applyPref()), this, SLOT(slotApplyPref()));

	// Show the dialog
	if (dlg.exec() == QDialog::Accepted) {
		// Verify Cscope's installation
		verifyCscope();
	}
*/
	return;
}

// Mon Apr  4 02:12:18 UTC 2011
