
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
#include "newprojectdlg4.h"
#include "projectbase4.h"
#include "projectmanager4.h"
#include "project4.h"
#include <qdebug.h>

namespace kscope4{
KScope::KScope(QWidget *) :
	m_bCscopeVerified(false) //,
	// m_pProgressDlg(NULL)
{
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


	// BEGIN STUFF FROM KSCOPE
	// Connect menu and toolbar items with the object's slots
	// m_pActions = new KScopeActions(this);
	// m_pActions->init();
	//m_pActions->slotEnableProjectActions(false);
	// END STUFF FROM KSCOPE
}

/**
 * Class destructor.
 */
KScope::~KScope()
{
	// Save configuration
	// Config().store();
	// Config().storeWorkspace(this);
	
	delete m_pProjMgr;
	/*
	delete m_pCallTreeMgr;
	delete m_pEditMgr;
	delete m_pCscopeBuild;
	
	if (m_pMakeDlg != NULL)
		delete m_pMakeDlg;
	*/
}

void KScope::setupActions()
{

	KStandardAction::open(this, SLOT(openFile()), actionCollection());

	// BEGIN KACTIONS
	KAction* clearAction = new KAction(this);
  	clearAction->setText(i18n("&Clear"));
	clearAction->setIcon(KIcon("document-new"));
	clearAction->setShortcut(Qt::CTRL + Qt::Key_W);
	actionCollection()->addAction("clear", clearAction);

	KAction* cscopeRebuild = new KAction(this);
  	cscopeRebuild->setText(i18n("cscope rebuild"));
	actionCollection()->addAction("cscope_rebuild", cscopeRebuild);
	connect(cscopeRebuild, SIGNAL(triggered(bool)),
	this, SLOT(slotRebuildDB()));

	KAction* projectNew = new KAction(this);
  	projectNew->setText(i18n("project_new"));
	actionCollection()->addAction("project_new", projectNew);
	connect(projectNew, SIGNAL(triggered(bool)),
	this, SLOT(slotCreateProject()));
	// END KACTIONS

	setXMLFile("kscope-kde4.rc");
	setupGUI(Default, "kscope-kde4.rc");
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

	connect(pVer, SIGNAL(done(bool, uint)), this,
		SLOT(slotCscopeVerified(bool, uint)));

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

/**
 * Handles the "Project->New..." command.
 * Prompts the user for the name and folder for the project, and then creates
 * the project.
 */
void KScope::slotCreateProject()
{
	NewProjectDlg dlg(true, this);
	ProjectBase::Options opt;
	QString sProjPath;
	
	qDebug() << "KScope::slotCreateProject() BEGIN \n";

	// Prompt the user to close any active projects
	if (m_pProjMgr->curProject()) {
		qDebug() << "KScope::slotCreateProject() Prompt the user to close any active projects \n";
		if (KMessageBox::questionYesNo(0, 
			i18n("The current project needs to be closed before a new one is"
			" created.\nWould you like to close it now?")) != 
			KMessageBox::Yes) {
			return;
		}
		
		// Try to close the project.
		if (!slotCloseProject())
			return;
	}
	
	// Display the "New Project" dialog
	if (dlg.exec() != QDialog::Accepted)
		return;

	// Create and open the new project
	dlg.getOptions(opt);

	if (m_pProjMgr->create(dlg.getName(), dlg.getPath(), opt, sProjPath))
		openProject(sProjPath);
}

/**
 * Closes the active project.
 * Closing a project involves closing all of the editor windows (prompting
 * the user for unsaved changes); terminating the Cscope process; and further
 * clean-up of the project's data.
 */
bool KScope::slotCloseProject()
{

	qDebug() << "KScope::slotCloseProject() FIXME: rebuild \n";
	return true;

	ProjectBase* pProj;
	Project::Session sess;

	
	// Do nothing if no project is open
	pProj = m_pProjMgr->curProject();
	if (!pProj)
		return true;
	
	/*
	// Make sure all FileLocation objects are deleted
	sess.fllOpenFiles.setAutoDelete(true);
	sess.fllBookmarks.setAutoDelete(true);
	
	// Close all open editor pages
	if (m_pEditTabs->count() > 0) {
		// Save session information for persistent projects
		if (!pProj->isTemporary()) {
			sess.sLastFile = m_pEditTabs->getCurrentPage()->getFilePath();
			m_pEditTabs->getOpenFiles(sess.fllOpenFiles);
			m_pEditTabs->getBookmarks(sess.fllBookmarks);
		}
		
		if (!m_pEditTabs->removeAllPages())
			return false;
	}
	
	// Disable project-related actions
	m_pActions->slotEnableProjectActions(false);
	
	// Destroy the make dialogue
	if (m_pMakeDlg != NULL) {
		// Save session information for persistent projects
		if (!pProj->isTemporary()) {
			sess.sMakeCmd = m_pMakeDlg->getCommand();
			sess.sMakeRoot = m_pMakeDlg->getDir();
		}
		
		delete m_pMakeDlg;
		m_pMakeDlg = NULL;
	}
	
	// Save session information for persistent projects
	if (!pProj->isTemporary()) {
		m_pQueryWidget->savePages(pProj->getPath(), sess.slQueryFiles);
		m_pCallTreeMgr->saveOpenDialogs(pProj->getPath(), sess.slCallTreeFiles);
	}
		
	// Close all query pages and call trees
	m_pQueryWidget->slotCloseAll();
	m_pCallTreeMgr->closeAll();
	
	// Store session information for persistent projects
	if (!pProj->isTemporary())
		((Project*)pProj)->storeSession(sess);
	
	// Close the project in the project manager, and terminate the Cscope
	// process
	m_pProjMgr->close();
	delete m_pCscopeBuild;
	m_pCscopeBuild = NULL;
	setCaption(QString::null);

	// Clear the contents of the file list
	m_pFileView->clear();

	// Reset queried symbols history
	SymbolDlg::resetHistory();
	
    // Remove any remaining status bar messages
    statusBar()->message("");
	*/
    
	return true;
}



/**
 * Handles the "Cscope->Rebuild Database..." command.
 * Rebuilds Cscope's database for the current project.
 */
void KScope::slotRebuildDB()
{
	ProjectBase* pProj;
	
	qDebug() << "KScope::slotRebuildDB() FIXME: rebuild \n";

	pProj = m_pProjMgr->curProject();
}
	/*
	if (!pProj)
		return;
	
	if (!pProj->dbExists()) {
		m_pProgressDlg = new ProgressDlg(i18n("KScope"), i18n("Please wait "
			"while KScope builds the database"), this);
		m_pProgressDlg->setAllowCancel(false);
		m_pProgressDlg->setValue(0);
	}
	
	m_pCscopeBuild->rebuild();
	*/



/**
 * Opens a project.
 * If another project is currently active, it is closed first.
 * @param	sDir	The directory of the project to open.
 */
void KScope::openProject(const QString& sDir)
{
	QString sProjDir;
	ProjectBase* pProj;
	QStringList slQueryFiles;
	QStringList slCallTreeFiles;
	QStringList slArgs;
	ProjectBase::Options opt;
	
	// Close the current project (may return false if the user clicks on the
	// "Cancel" button while prompted to save a file)
	if (!slotCloseProject())
		return;

	// Open the project in the project manager
	sProjDir = QDir::cleanPath(sDir);
	/*
	if (!m_pProjMgr->open(sProjDir))
		return;
	*/
	
	// Change main window title
	pProj = m_pProjMgr->curProject();
	setCaption(pProj->getName());

	// Set the root of the file tree
	// m_pFileView->setRoot(pProj->getSourceRoot());
	
	// Initialise Cscope and create a builder object
	// initCscope();
	
	// Set auto-completion parameters
	pProj->getOptions(opt);
	// SymbolCompletion::initAutoCompletion(opt.bACEnabled, opt.nACMinChars,
		//opt.nACDelay, opt.nACMaxEntries);
	
	// Set per-project command-line arguments for Ctags
	// CtagsFrontend::setExtraArgs(opt.sCtagsCmd);
	
	// Create an initial query page
	// m_pQueryWidget->addQueryPage();
	
	// Enable project-related actions
	// m_pActions->slotEnableProjectActions(true);
	
	// If this is a new project (i.e., no source files are yet included), 
	// display the project files dialogue
	/*
	if (pProj->isEmpty()) {
		slotProjectFiles();
		return;
	}
	*/
	
	// Fill the file list with all files in the project. 
	// m_pFileList->setUpdatesEnabled(false);
	// pProj->loadFileList(m_pFileList);
	// m_pFileList->setUpdatesEnabled(true);
	
	// Restore the last session
	// restoreSession();
	
	// Rebuild the cross-reference database
	/*
	if (isAutoRebuildEnabled()) {
		// If Cscope installation was not yet verified, postpone the build
		// process
		if (m_bCscopeVerified)
		slotRebuildDB();
		else
			m_bRebuildDB = true;
	}
	*/
}

} // namespace kscope4
// Tue Jun 14 03:07:28 UTC 2011
