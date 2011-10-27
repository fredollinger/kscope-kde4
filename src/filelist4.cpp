#include <qlineedit.h>
#include <qfileinfo.h>
#include <klocale.h>
#include "filelist4.h"
#include "kscopeconfig4.h"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
FileList::FileList(QWidget* pParent, const char* szName) :
	SearchList(1, pParent, szName),
	m_sRoot("/")
{
	// Set the list's columns
	/*
	m_pList->addColumn("");
	m_pList->addColumn(i18n("File"));
	m_pList->addColumn(i18n("Path"));
	
	// Sort only when asked to by the user
	if (Config().getAutoSortFiles())
		m_pList->setSortColumn(1);
	else
		m_pList->setSortColumn(m_pList->columns() + 1);
	
	m_pList->setAllColumnsShowFocus(true);
	
	// Set colours and font
	applyPrefs();
	*/
}

/**
 * Class destructor.
 */
FileList::~FileList()
{
}

/**
 * Adds a single entry to the file list.
 * Implements the addItem() virtual method of the FileListTarget base
 * class. When a FileList object is given as a parameter to
 * ProjectManager::fillList(), this method is called for each file included
 * in the project. A new list item is created, containing the file's name and
 * path, and is added to the list.
 * @param	sFilePath	The full path of a source file
 */
void FileList::addItem(const QString& sFilePath)
{
	QString sFileType, sFileName, sPath;
	int nTypePos;

    // Extract the file name
    // sFileName = sFilePath.mid(sFilePath.findRev('/') + 1);
		
	// Get the file's extension (empty string for file names without an
	// extension)
	// nTypePos = sFileName.findRev('.');
	if (nTypePos > -1)
		sFileType = sFileName.mid(nTypePos + 1);
	
	// If a root path has been set, use a $ sign instead of that part of the
	// path
	sPath = sFilePath;
	if (m_sRoot != "/")
		sPath.replace(m_sRoot, "$");
	
	// Create the list item
	// new QListWidgetItem(m_pList, sFileType, sFileName, sPath);
}

/**
 * Searches the list for the given file path.
 * @param	sPath	The full path of the file to find
 * @return	true if the file was found in the list, false otherwise
 */
bool FileList::findFile(const QString& sPath)
{
	QString sFindPath(sPath);
	
	if (m_sRoot != "/")
		sFindPath.replace(m_sRoot, "$");
	
	return true;
	// return (m_pList->findItem(sFindPath, 2) != NULL);
}

/**
 * Removes all items from the file list.
 */
void FileList::clear()
{
	// m_pList->clear();
	m_pEdit->setText("");
}

/**
 * Opens a file for editing when its entry is clicked in the file list.
 * @param	pItem	The clicked list item
 */
/*
void FileList::processItemSelected(QListWidgetItem* pItem)
{
	QString sPath;

	// Get the file path (replace the root symbol, if required)
	sPath = pItem->text(2);
	if (sPath.startsWith("$"))
		sPath.replace("$", m_sRoot);
		
	// Submit a request to open the file for editing
	emit fileRequested(sPath, 0);
}
*/

/**
 * Sets the list's colours and font, according the user's preferences.
 */
void FileList::applyPrefs()
{
	// Apply colour settings
	// m_pList->setPaletteBackgroundColor(Config().getColor(
		//KScopeConfig::FileListBack));
	// m_pList->setPaletteForegroundColor(Config().getColor(
		//KScopeConfig::FileListFore));
	// m_pList->setFont(Config().getFont(KScopeConfig::FileList));
}

/**
 * Associates a root directory with this list.
 * For each file in the list, the part of the path corresponding to the root
 * is replaced with a $ sign.
 * @param	sRoot	The new root path
 */
void FileList::setRoot(const QString& sRoot)
{
	QListWidgetItem* pItem;
	QString sPath;
	
	// Update all items in the list
	/*
	for (pItem = m_pList->firstChild(); pItem != NULL; 
		pItem = pItem->nextSibling()) {
		sPath = pItem->text(2);
		
		// Restore the full path
		sPath.replace("$", m_sRoot);
		
		// Replace the root with a $ sign
		if (sRoot != "/")
			sPath.replace(sRoot, "$");
		
		pItem->setText(2, sPath);
	}
	*/
	
	// Store the new root
	m_sRoot = sRoot;
}

// #include "filelist.moc"
