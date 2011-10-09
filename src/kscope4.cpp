#include <kparts/part.h>

#include <KActionCollection>
#include <KFileDialog>
#include <KMessageBox>
#include <KStandardAction>
#include <KStatusBar>
#include <KSystemTrayIcon>
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>
#include <KXMLGUIFactory>

#include <QDockWidget>
#include <QFile>

// #include "calltreedlg4.h"
// #include "calltreemanager4.h"
#include "fileview4.h"
#include "cscopefrontend4.h"
#include "openprojectdlg4.h"
#include "editormanager4.h"
#include "kscope4.h"
#include "kdockwidget4.h"
#include "newprojectdlg4.h"
#include "projectbase4.h"
#include "projectmanager4.h"
#include "project4.h"
#include "symbolcompletion4.h"
#include "symboldlg4.h"
#include "querywidget4.h"

#include <qdebug.h>

namespace kscope4{
KScope::KScope(QWidget *) :
	m_bCscopeVerified(false),
	m_pCscopeBuild(NULL),
	m_pProgressDlg(NULL)
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
	// m_pQueryWidget = new QueryWidget(this);

	createDockWindows();

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
	// BEGIN version control menu
	KAction* vcsCommit = new KAction(this);
  	vcsCommit->setText(i18n("Commit/Submit"));
	actionCollection()->addAction("vcs_commit", vcsCommit);
	connect(vcsCommit, SIGNAL(triggered(bool)),
	this, SLOT(slotCommit()));

	KAction* vcsPush = new KAction(this);
  	vcsPush->setText(i18n("Push"));
	actionCollection()->addAction("vcs_push", vcsPush);
	connect(vcsPush, SIGNAL(triggered(bool)),
	this, SLOT(slotPush()));

	// END version control menu

	KAction* clearAction = new KAction(this);
  	clearAction->setText(i18n("&Clear"));
	clearAction->setIcon(KIcon("document-new"));
	clearAction->setShortcut(Qt::CTRL + Qt::Key_W);
	actionCollection()->addAction("clear", clearAction);

	// BEGIN Cscope Menu
	KAction* cscopeRebuild = new KAction(this);
  	cscopeRebuild->setText(i18n("cscope rebuild"));
	actionCollection()->addAction("cscope_rebuild", cscopeRebuild);
	connect(cscopeRebuild, SIGNAL(triggered(bool)),
	this, SLOT(slotRebuildDB()));

	KAction* cscopeText = new KAction(this);
  	cscopeText->setText(i18n("Find &EGrep Pattern..."));
	actionCollection()->addAction("cscope_text", cscopeText);
	connect(cscopeText, SIGNAL(triggered(bool)),
	this, SLOT(slotQueryPattern()));
	// END Cscope Menu

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

void KScope::openFileNamed(QString name)
{
	QFile *file = new QFile(name);

	if (!file->open(QIODevice::ReadOnly | QIODevice::Text)){
		qDebug() << file << " does not exist! \n";
        	return;
	}


	QByteArray *ba = new QByteArray(file->readAll());
	QString qs = QString(ba->data());
	m_view->document()->setText(qs);	
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

// #if 0 BEGIN WORKING  initMainWindow
void KScope::initMainWindow()
{
	KDockWidget* pMainDock;
	KStatusBar* pStatus;

	// Create the status bar
	pStatus = statusBar();
	pStatus->insertItem(i18n(" Line: N/A Col: N/A "), 0, 0);

// /home/follinge/projects/kscope-kde4/src/kscope4.cpp:178:34: error: no matching function for call to ‘kscope4::KScope::splitDockWidget(KTextEditor::View*&, QListView*&)’
// /usr/include/qt4/QtGui/qmainwindow.h:169:10: note: candidate is: void QMainWindow::splitDockWidget(QDockWidget*, QDockWidget*, Qt::Orientation)
//	splitDockWidget(m_view, listView);

	return;
}
// #if 0 END WORKING  initMainWindow

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
	*/
    statusBar()->clearMessage();
    
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
/*
void KScope::openProject(const QString& sDir)
{
	QString sProjDir;
	ProjectBase* pProj;
	QStringList slQueryFiles;
	QStringList slCallTreeFiles;
	QStringList slArgs;
	ProjectBase::Options opt;
	
	qDebug() << "KScope::slotOpenProject() BEGIN \n";

	// Close the current project (may return false if the user clicks on the
	// "Cancel" button while prompted to save a file)
	if (!slotCloseProject())
		return;

	// FIXME:
	qDebug() << "KScope::slotOpenProject() crashing?? \n";
	// Open the project in the project manager
	sProjDir = QDir::cleanPath(sDir);
	if (!m_pProjMgr->open(sProjDir))
		return;
	
	// Change main window title
	pProj = m_pProjMgr->curProject();
	setCaption(pProj->getName());

	// Set the root of the file tree
	m_pFileView->setRoot(pProj->getSourceRoot());
	return;
	
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
	if (pProj->isEmpty()) {
		slotProjectFiles();
		return;
	}
	
	// Fill the file list with all files in the project. 
	// m_pFileList->setUpdatesEnabled(false);
	// pProj->loadFileList(m_pFileList);
	// m_pFileList->setUpdatesEnabled(true);
	
	// Restore the last session
	// restoreSession();
	
	// Rebuild the cross-reference database
	if (isAutoRebuildEnabled()) {
		// If Cscope installation was not yet verified, postpone the build
		// process
		if (m_bCscopeVerified)
		slotRebuildDB();
		else
			m_bRebuildDB = true;
	}
}
*/

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
	
	// Prompt the user to close any active projects
	if (m_pProjMgr->curProject()) {
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
 * Handles the "Project->Open..." command.
 * Prompts the user for a project file ("cscope.proj"), and opens the
 * selected project.
 */
void KScope::slotOpenProject()
{
	OpenProjectDlg dlg;
	QString sPath;
	
	if (dlg.exec() == QDialog::Rejected)
		return;

	sPath = dlg.getPath();
	
	// Check if the path refers to a permanent or temporary project
	if (QFileInfo(sPath).isDir())
		openProject(sPath);
	else
		openCscopeOut(sPath);
}

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
	if (!m_pProjMgr->open(sProjDir))
		return;
	
	// Change main window title
	pProj = m_pProjMgr->curProject();
	setCaption(pProj->getName());

	// Set the root of the file tree
	m_pFileView->setRoot(pProj->getSourceRoot());
	
	// Initialise Cscope and create a builder object
	/*
	initCscope();
	
	// Set auto-completion parameters
	pProj->getOptions(opt);
	SymbolCompletion::initAutoCompletion(opt.bACEnabled, opt.nACMinChars,
		opt.nACDelay, opt.nACMaxEntries);
	
	// Set per-project command-line arguments for Ctags
	CtagsFrontend::setExtraArgs(opt.sCtagsCmd);
	
	// Create an initial query page
	m_pQueryWidget->addQueryPage();
	
	// Enable project-related actions
	m_pActions->slotEnableProjectActions(true);
	
	// If this is a new project (i.e., no source files are yet included), 
	// display the project files dialogue
	if (pProj->isEmpty()) {
		slotProjectFiles();
		return;
	}
	
	// Fill the file list with all files in the project. 
	m_pFileList->setUpdatesEnabled(false);
	pProj->loadFileList(m_pFileList);
	m_pFileList->setUpdatesEnabled(true);
	
	// Restore the last session
	restoreSession();
	
	// Rebuild the cross-reference database
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

/**
 * Opens a temporary project for a Cscope.out file.
 * @param	sFilePath	The full path of the Cscope.out file
 * @return	true if successful, false otherwise
 */
bool KScope::openCscopeOut(const QString& sFilePath)
{
	ProjectBase* pProj;
	
	// Close the current project (may return false if the user clicks on the
	// "Cancel" button while prompted to save a file)
	if (!slotCloseProject())
		return false;

	// Open a temporary project for this cscope.out file
	if (!m_pProjMgr->openCscopeOut(sFilePath))
		return false;
	
	// Change main window title
	pProj = m_pProjMgr->curProject();
	setCaption(pProj->getName());
	
	// Set the root folder in the file tree
	m_pFileView->setRoot(pProj->getSourceRoot());
	
	// Initialise Cscope and create a builder object
	/*
	initCscope();
	
	// Create an initial query page
	m_pQueryWidget->addQueryPage();
	
	// Enable project-related actions
	m_pActions->slotEnableProjectActions(true);
	
	// Fill the file list with all files in the project. 
	m_pFileList->setUpdatesEnabled(false);
	pProj->loadFileList(m_pFileList);
	m_pFileList->setUpdatesEnabled(true);
	*/
	
	return true;
}

/**
 * Handles the "Cscope->Find EGrep Pattern..." menu command.
 * Prompts the user for a regular expression, and initiates a query to find 
 * all strings matching that pattern.
 */
void KScope::slotQueryPattern()
{
	slotQuery(SymbolDlg::Pattern, true);
}

#if 0 
// BEGIN slotQuery WORKS
/**
 * Promts the user for a symbol, an starts a new Cscope query.
 * @param	nType	The numeric query type code
 * @param	bPrompt	true to always prompt for a symbol, false to try to
 * 					obtain the symbol automatically
 */
void KScope::slotQuery(uint nType, bool bPrompt)
{
	qDebug() << "slotQuery() FIXME: Not done \n";

	QString sSymbol;
	bool bCase;
	// CallTreeDlg* pCallTreeDlg;

	// Get the requested symbol and query type
	if (!getSymbol(nType, sSymbol, bCase, bPrompt))
		return;
		
	/*
	if (nType == SymbolDlg::CallTree) {
		// Create and display a call tree dialogue
		// pCallTreeDlg = m_pCallTreeMgr->addDialog();
		// pCallTreeDlg->setRoot(sSymbol);
		// pCallTreeDlg->show();
	}
	else { */
	// Run the requested query
	nType = SymbolDlg::getQueryType(nType);

	// m_pQueryWidget->initQuery(nType, sSymbol, bCase);
		
	// Ensure Query Window is visible
	//toggleQueryWindow(true);	
	// }
}
// END slotQuery()
#endif 

/**
 * Prompts the user for a symbol to query.
 * Shows a dialog with a line edit widget, where the user can enter a symbol
 * on which to query Cscope. The meaning of the symbol depends on the type of
 * query.
 * @param	nType	The requested type of query (may be changed in the
 *					dialogue)
 * @param	sSymbol	Holds the requested symbol, upon successful return
 * @param	bPrompt	If false, the user is prompted only if a symbol cannot be
 *					determined automatically
 * @return	true if the user hs enetered a symbol, false otherwise
 */
bool KScope::getSymbol(uint& nType, QString& sSymbol, bool& bCase,
	bool bPrompt)
{
	EditorPage* pPage;
	QString sSuggested;
	
	// Set the currently selected text, if any
	// if ((pPage = m_pEditTabs->getCurrentPage()) != NULL)
	//	sSuggested = pPage->getSuggestedText();

	// Return if a symbol was found, and prompting is turned off
	if (!sSuggested.isEmpty() && !bPrompt) {
		sSymbol = sSuggested;
		return true;
	}
	
	// Show the symbol dialogue
	sSymbol = SymbolDlg::promptSymbol(this, nType, sSuggested, bCase);

	// Cannot accept empty strings
	if (sSymbol.isEmpty())
		return false;
	
	return true;
}
// END getSymbol()

/**
 * Reports progress information from the Cscope process responsible for
 * rebuilding the cross-reference database.
 * This slot is connected to the progress() signal emitted by the builder
 * process.
 * Progress information is displayed in the status bar.
 * @param	nFiles	The number of files scanned
 * @param	nTotal	The total number of files in the project
 */
void KScope::slotBuildProgress(int nFiles, int nTotal)
{
	QString sMsg;
	
	// Use the progress dialogue, if it exists (first time builds)
	if (m_pProgressDlg) {
		m_pProgressDlg->setValue((nFiles * 100) / nTotal);
		return;
	}
	
	// Show progress information
	sMsg = i18n("Rebuilding the cross reference database...") + " " +
		QString::number((nFiles * 100) / nTotal) + "%";
	statusBar()->showMessage(sMsg);
}


/**
 * Reports to the user that Cscope has started building the inverted index.
 * This slot is connected to the buildInvIndex() signal emitted by the 
 * builder process.
 */
void KScope::slotBuildInvIndex()
{
	if (m_pProgressDlg) {
		m_pProgressDlg->setLabelText(i18n("Please wait while KScope builds the "
			"inverted index"));
		m_pProgressDlg->setIdle();
		return;
	}
	
	statusBar()->showMessage(i18n("Rebuilding inverted index..."));
}


/**
 * Informs the user the database rebuild process has finished.
 * This slot is connected to the finished() signal emitted by the builder
 * process.
 */
void KScope::slotBuildFinished(uint)
{
	// Delete the progress dialogue, if it exists (first time builds)
	if (m_pProgressDlg) {
		delete m_pProgressDlg;
		m_pProgressDlg = NULL;
		return;
	}
	
	// Show a message in the status bar
	statusBar()->showMessage(i18n("Rebuilding the cross reference database..."
		"Done!"), 3000);
}


/**
 * Called if the build process failed to complete.
 * This slot is connected to the aborted() signal emitted by the builder
 * process.
 */
void KScope::slotBuildAborted()
{
	// Delete the progress dialogue, if it exists (first time builds)
	if (m_pProgressDlg) {
		delete m_pProgressDlg;
		m_pProgressDlg = NULL;
	
		// Display a failure message
		KMessageBox::error(0, i18n("The database could not be built.\n"
			"Cross-reference information will not be available for this "
			"project.\n"
			"Please ensure that the Cscope parameters were correctly "
			"entered in the \"Settings\" dialogue."));		
		return;
	}
	
	// Show a message in the status bar
	statusBar()->showMessage(i18n("Rebuilding the cross reference database..."
		"Failed"), 3000);	
}

/**
 * Displays error messages from a Cscope process.
 * This slot is connected to the progress() signal emitted by the any
 * Cscope process.
 * @param	sMsg	The error message
 */
void KScope::slotCscopeError(const QString& sMsg)
{
	qDebug() << "KScope::slotCscopeError() \n";
	// m_pMsgDlg->addText(sMsg);
}

/**
 * Initialises the CscopeFrontend class with the current project arguments,
 * and creates an object used for rebuilding the symbol database.
 */
void KScope::initCscope()
{
	ProjectBase* pProj;
	
	// Delete the current object, if one exists
	if (m_pCscopeBuild)
		delete m_pCscopeBuild;

	// Initialise CscopeFrontend
	pProj = m_pProjMgr->curProject();
	CscopeFrontend::init(pProj->getPath(), pProj->getArgs());

	// Create a persistent Cscope process
	m_pCscopeBuild = new CscopeFrontend();

	// Show build progress information in the main status bar
	connect(m_pCscopeBuild, SIGNAL(progress(int, int)), this,
		SLOT(slotBuildProgress(int, int)));
	connect(m_pCscopeBuild, SIGNAL(buildInvIndex()), this,
		SLOT(slotBuildInvIndex()));
	connect(m_pCscopeBuild, SIGNAL(finished(uint)), this,
		SLOT(slotBuildFinished(uint)));
	connect(m_pCscopeBuild, SIGNAL(aborted()), this,
		SLOT(slotBuildAborted()));

	// Show errors in a modeless dialogue
	connect(m_pCscopeBuild, SIGNAL(error(const QString&)), this,
		SLOT(slotCscopeError(const QString&)));
}

/**
 * Shows or hides the query dock window.
 * This function is only called internally, not as a result of a user's
 * workspace action (e.g., clicking the "Show/Hide Query Window" toolbar
 * button). Therefore it does not reflect the user's preference, which is
 * kept through the m_bHideQueryOnSelection variable.
 * @param	bShow	true to show the window, false to hide it
 */
void KScope::toggleQueryWindow(bool bShow)
{
	// Remember the user's preferences
	if (bShow)
		m_bHideQueryOnSelection = m_pQueryDock->isVisible();
	else
		m_bHideQueryOnSelection = false;
	
	// Change the visibility state of the widget, if required
	if (m_pQueryDock->isVisible() != bShow)
		m_pQueryDock->changeHideShowState();
		
	// Synchronise with the menu command's state
	// m_pActions->slotQueryDockToggled(bShow);
}

void KScope::slotCommit(){
	qDebug() << "slotCommit";
}

// BEGIN createDockWindow()
void KScope::createDockWindows(){
     resDock = new QDockWidget(i18n("Files"), this);
     resDock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
     customerList = new QListWidget(resDock);
     customerList->addItems(QStringList()
             << "kscope4.h"
             << "main_menu.cpp"
             << "kscope4.cpp");
     resDock->setWidget(customerList);
     addDockWidget(Qt::BottomDockWidgetArea, resDock);
}
// END createDockWindow()

/**
 * Promts the user for a symbol, an starts a new Cscope query.
 * @param	nType	The numeric query type code
 * @param	bPrompt	true to always prompt for a symbol, false to try to
 * 					obtain the symbol automatically
 */
void KScope::slotQuery(uint nType, bool bPrompt)
{

	// slotQuery(SymbolDlg::Pattern, true);
	QString sSymbol;
	// CallTreeDlg* pCallTreeDlg;
	bool bCase;
	
	// Get the requested symbol and query type
	if (!getSymbol(nType, sSymbol, bCase, bPrompt))
		return;

	if (nType == SymbolDlg::Pattern) {
		// Run the requested query
		nType = SymbolDlg::getQueryType(nType);
		qDebug() << "KScope::slotQuery() NOT IMPLEMENTED! \n";
		qDebug() << "KScope::slotQuery()  m_pQueryWidget->initQuery(nType, sSymbol, bCase); \n";
		// m_pQueryWidget->initQuery(nType, sSymbol, bCase);
		
		// Ensure Query Window is visible
		toggleQueryWindow(true);	
	}
	else qDebug() << "KScope::slotQuery() NOT IMPLEMENTED! \n";
}


} // namespace kscope4
// Sun Oct  9 07:35:27 PDT 2011
