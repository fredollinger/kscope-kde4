#include <qpushbutton.h>
#include <qfileinfo.h>
#include <qtabwidget.h>
#include <kfiledialog.h>
#include "fileview4.h"
#include "filelist4.h"
#include "kscopepixmaps4.h"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 * @param	fl		Widget creation flags
 */
FileView::FileView(QWidget* pParent, const char* szName, Qt::WFlags fl) :
	Ui::FileViewLayout(),
	m_pCurBranch(0),
	m_sRoot("")
{
	QWidget* pPage;
	
	// Set the tab widget icons
	//pPage = m_pTabWidget->page(0);
	// m_pTabWidget->setTabIconSet(pPage, GET_PIXMAP(TabFileList));
	// pPage = m_pTabWidget->page(1);
	// m_pTabWidget->setTabIconSet(pPage, GET_PIXMAP(TabFileTree));
	
	// Create a single column for the file tree
	// m_pFileTree->addColumn("");
	
	// Send the fileRequested() signal whenever a file is selected in either
	// the list or the tree
	connect(m_pFileList, SIGNAL(fileRequested(const QString&, uint)), this,
		SIGNAL(fileRequested(const QString&, uint)));
	// connect(m_pFileTree, SIGNAL(doubleClicked(QTreeWidgetItem*)), 
		//this, SLOT((QTreeWidgetItem*)));
	//connect(m_pFileTree, SIGNAL(returnPressed(QListViewItem*)), this, 
	//	SLOT(slotTreeItemSelected(QListViewItem*)));
}

/**
 * Class destructor.
 */
FileView::~FileView()
{
}

/**
 * Sets a new common root path to both the file list and the tree.
 * @param	sRoot	The full path of the new root
 */
void FileView::setRoot(const QString& sRoot)
{
	// Nothing to do if the given root is the same as the old one
	if (sRoot == m_sRoot)
		return;
	
	m_sRoot = sRoot;
	
	// Remove the current branch
	// if (m_pCurBranch)
		//m_pFileTree->removeBranch(m_pCurBranch);
	
	// Update the file list
	m_pFileList->setRoot(sRoot);
	
	// Nothing more to do for an empty root directory
	if (sRoot.isEmpty())
		return;
	
	// Create and open a new branch, with the newly specified root
	QFileInfo fi(sRoot);
	// m_pCurBranch = m_pFileTree->addBranch(KURL(sRoot), fi.fileName());
	m_pCurBranch->setChildRecurse(false);
	//m_pFileTree->setOpen(m_pCurBranch->root(), true);
}

/**
 * Clears the contents of the file view and file tree.
 */
void FileView::clear()
{
	m_pFileList->clear();
	setRoot("");
} 

/**
 * Emits the fileRequested() signal when a file name is selected in the file 
 * tree. An item is selected by either double-clicking it or by hittin 
 * "ENTER" when it is highlighted.
 * This slot is connected to the doubleClicked() and returnPressed() signals
 * of the KFileTreeView object.
 * @param	pItem	The selected tree item
 */
/*
void FileView::slotTreeItemSelected(QListViewItem* pItem)
{
	KFileTreeViewItem* pTreeItem;
	 
	pTreeItem = (KFileTreeViewItem*)pItem;
	if (pTreeItem && !pTreeItem->isDir())
		emit fileRequested(pTreeItem->path(), 0);
}
*/

// #include "fileview.moc"
// Sun Jul 10 21:04:31 UTC 2011
