#include <qfileinfo.h>
#include <klocale.h>
#include <kmessagebox.h>
// #include <kurldrag.h>
// #include <kate/document.h>
#include "editortabs4.h"
#include "queryview4.h"
#include <QMenu>

/**
 * Class constructor.
 * @param	pParent		The parent widget
 * @param	szName		The widget's name
 */
EditorTabs::EditorTabs(QWidget* pParent, const char* szName) :
	TabWidget(pParent),
	m_pCurPage(NULL),
	m_nWindowMenuItems(0),
	m_nNewFiles(0)
{
	// Display close buttons
	setHoverCloseButton(true);

	// Accept file drops
	setAcceptDrops(true);
	
	// Close an editor page when its close button is clicked
	connect(this, SIGNAL(closeRequest(QWidget*)), this,
		SLOT(slotRemovePage(QWidget*)));
	
	// Set an editor page as the active part, when its tab is selected	
	connect(this, SIGNAL(currentChanged(QWidget*)), this,
		SLOT(slotCurrentChanged(QWidget*)));

	// Start dragging a file from a tab
	connect(this, SIGNAL(initiateDrag(QWidget*)), this,
		SLOT(slotInitiateDrag(QWidget*)));
}

/**
 * Class destructor.
 */
EditorTabs::~EditorTabs()
{
}

/**
 * @param	pWindowMenu	Pointer to the main window's "Window" menu (used to
 * 						add an activation menu item for each editor page)
 */
#if 0
void EditorTabs::setWindowMenu(QPopupMenu* pWindowMenu)
{
	m_pWindowMenu = pWindowMenu;
	connect(pWindowMenu, SIGNAL(aboutToShow()), this,
		SLOT(slotFillWindowMenu()));
	connect(pWindowMenu, SIGNAL(activated(int)), this,
		SLOT(slotSetCurrentPage(int)));
}
#endif

/**
 * Adds a new editor page to the tab widget.
 * @param	pNewPage	The page to add
 */
void EditorTabs::addEditorPage(EditorPage* pNewPage)
{
	// Create a new tab and set is as the current one
	//insertTab(pNewPage, "");
	//showPage(pNewPage);

	// Add the file edited by this page to the map, and display its name,
	// once the file is opened
	connect(pNewPage, SIGNAL(fileOpened(EditorPage*, const QString&)), this,
		SLOT(slotAttachFile(EditorPage*, const QString&)));

	// Handle new unnamed files
	connect(pNewPage, SIGNAL(newFile(EditorPage*)), this,
		SLOT(slotNewFile(EditorPage*)));
	
	// Change tab icon when a file is modified
	connect(pNewPage, SIGNAL(modified(EditorPage*, bool)), this,
		SLOT(slotFileModified(EditorPage*, bool)));
	
	// If this is the first page, the current page will not be set by the 
	// signal handler, so we need to do it manually
	//if (count() == 1)
	//	slotCurrentChanged(pNewPage);
}

/**
 * Finds and displays a page editing the given file.
 * NOTE: The bForceChange parameters is used as a fix for the GUI merge
 * problem arising when the found page is the current one.
 * @param	sFileName		The name of the file to search
 * @param	bForceChange	If set to true, the method will emit the signal
 *							editorChanged() even if the found page is the
 *							current one
 * @return	The editor page object, if found, NULL otherwise
 */
EditorPage* EditorTabs::findEditorPage(const QString& sFileName,
	bool bForceChange)
{
	EditorMap::iterator itr;
	EditorPage* pPage;
	bool bEmit;
	
	// Find the page according to the associated file name
	itr = m_mapEdit.find(sFileName);
	if (itr == m_mapEdit.end())
		return NULL;

	// Set the page as the current one
	pPage = *itr;
	bEmit = (bForceChange && (pPage == m_pCurPage));
	// showPage(pPage);

	// Emit the editorChanged() signal, if required
	if (bEmit)
		emit editorChanged(NULL, m_pCurPage);
		
	return *itr;
}

/**
 * Returns the page associated with the selected tab.
 * @return	The current editor page
 */
/*
EditorPage* EditorTabs::getCurrentPage()
{
	//return (EditorPage*)currentPage();
}
*/

/**
 * Deletes the currently active page.
 * Finds the current page, closes its editor window and deletes the page.
 * If other editors are open, another page becomes active.
 */
void EditorTabs::removeCurrentPage()
{
	QWidget* pPage;

	// Get the active page, if any
	//pPage = currentPage();
	if (pPage == NULL)
		return;

	// Close the editor window
	removePage(pPage, false);
}

/**
 * Removes all editor pages.
 * @return	true if successful, false if the user aborts the operation
 */
bool EditorTabs::removeAllPages()
{
	QWidget* pPage;
	
	// Check if there are any modified files
	if (getModifiedFilesCount()) {
		// Prompt the user to save these files
		switch (KMessageBox::questionYesNoCancel(NULL,
			i18n("Some files contain unsaved changes.\nWould you like to "
			"save these files?"))) {
			case KMessageBox::Yes:
				// Save files
				slotSaveAll();
				break;
				
			case KMessageBox::No:
				// Close files, ignoring changes
				break;
				
			case KMessageBox::Cancel:
				// Abort
				return false;
		}
	}
	
	// Avoid warning about modification on disk
	//Kate::Document::setFileChangedDialogsActivated(false);
	
	// Iterate pages until none is left
	//while ((pPage = currentPage()) != NULL)
		//removePage(pPage, true);
	
	// Restore kate warning if enabled
	//Kate::Document::setFileChangedDialogsActivated(
	//	Config().getWarnModifiedOnDisk());
	
	// All pages were successfully removed
	return true;
}

/**
 * Keeps track of the currently active editor page, and notifies on a change
 * in the active page.
 * This slot is connected to the currentChanged() signal of the QTabWidget 
 * object.
 * @param	pWidget	The new active page
 */
void EditorTabs::slotCurrentChanged(QWidget* pWidget)
{
	EditorPage* pOldPage;

	// TODO:
	// For some reason, this slot is being called twice for every external
	// tab activation (e.g., through the Window menu).
	// We avoid it, but this really needs to be fixed properly.
	//if (pWidget == m_pCurPage)
	//	return;

	// Set the new active page
	pOldPage = m_pCurPage;
	m_pCurPage = (EditorPage*)pWidget;

	if (m_pCurPage) {
		// Set the keyboard focus to the editor part of the page
		//m_pCurPage->setEditorFocus();
		
		// Adjust the splitter sizes
		//m_pCurPage->setLayout(Config().getShowTagList(),
		//	Config().getEditorSizes());
	}
	
	/* Notify the main window */
	emit editorChanged(pOldPage, m_pCurPage);
}

/**
 * Updates the tab of an editor page to reflect the newly opened file.
 * This slot is attached to the fileOpened() signal of an EditorPage object.
 * @param	pEditPage	Pointer to the calling object
 * @param	sFilePath	The full path of the file edited in this page
 */
void EditorTabs::slotAttachFile(EditorPage* pEditPage,
	const QString& sFilePath)
{
	// Set the appropriate tab icon, according to the file permissions
	/*
	if (pEditPage->isWritable())
		setTabIconSet(pEditPage, Pixmaps().getPixmap(KScopePixmaps::TabRW));
	else
		setTabIconSet(pEditPage, Pixmaps().getPixmap(KScopePixmaps::TabRO));
	*/
	
	// Do nothing if the file name has not changed
	if (m_mapEdit[sFilePath] == pEditPage)
		return;

	// Set the tab caption to the file name, and a tool-tip to the full path
	//changeTab(pEditPage, pEditPage->getFileName());
	//setTabToolTip(pEditPage, sFilePath);

	// Associate the EditorPage object with its file name
	m_mapEdit[sFilePath] = pEditPage;
}

/**
 * Marks a page as containing a new unnamed file.
 * This slot is attached to the newFile() signal of an EditorPage object.
 * @param	pEditPage	Pointer to the calling object
 */
void EditorTabs::slotNewFile(EditorPage* pEditPage)
{
	QString sCaption;
	
	// Set the tab caption to mark a new file
	m_nNewFiles++;
	sCaption = i18n("Untitled ") + QString::number(m_nNewFiles);
	/*
	changeTab(pEditPage, 
		//Pixmaps().getPixmap(KScopePixmaps::TabRW),
		sCaption);
	*/
	//setTabToolTip(pEditPage, i18n("New unsaved file"));
}

/**
 * Fills a list with the paths and cursor positions of all files currently
 * open.
 * @param	list	The list to fill
 */
#if 0
void EditorTabs::getOpenFiles(FileLocationList& list)
{
	int i;
	EditorPage* pPage;
	uint nLine, nCol;
	
	// Iterate over all editor pages
	for (i = 0; i < count(); i++) {
		// Obtain file and cursor position information
		pPage = (EditorPage*)page(i);
		if (!pPage->getCursorPos(nLine, nCol)) {
			nLine = 1;
			nCol = 1;
		}
		
		// Create a new list item
		list.append(new FileLocation(pPage->getFilePath(), nLine, nCol));
	}
}
#endif 

/**
 * Constructs a list bookmarks set to open files.
 * Used to store all currently set bookmarks when a session is closed.
 * @param	fll	The list to fill
 */
#if 0
void EditorTabs::getBookmarks(FileLocationList& fll)
{
	int i;
	EditorPage* pPage;
	
	// Iterate over all editor pages
	for (i = 0; i < count(); i++) {
		pPage = (EditorPage*)page(i);
		pPage->getBookmarks(fll);
	}
}
#endif

#if 0
/**
 * Assigns bookmarks to open files.
 * Called when a session is opened, to restore any bookmarks set to existing
 * editor pages.
 * @param	fll	A list of bookmark positions
 */
void EditorTabs::setBookmarks(FileLocationList& fll)
{
	FileLocation* pLoc;
	EditorMap::iterator itr;
	EditorPage* pPage;
	
	// Iterate over the list of bookmarks
	for (pLoc = fll.first(); pLoc; pLoc = fll.next()) {
		itr = m_mapEdit.find(pLoc->m_sPath);
		// Get the relevant page, if any
		if (itr != m_mapEdit.end()) {
			pPage = *itr;
			pPage->addBookmark(pLoc->m_nLine);
		}
	}
}
#endif

/**
 * Saves all files open for editing.
 */
void EditorTabs::slotSaveAll()
{
	//int i;
	
	// Iterate through pages
	//for (i = 0; i < count(); i++)
	//	((EditorPage*)page(i))->save();
}

void EditorTabs::dragMoveEvent(QDragMoveEvent *w){
}

void EditorTabs::dropEvent(QDropEvent *w){
}

int EditorTabs::getModifiedFilesCount(){
	return 0;
}


// Sat Feb 18 15:59:04 PST 2012
