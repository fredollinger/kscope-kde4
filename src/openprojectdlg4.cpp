#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlistbox.h>
#include <kurlrequester.h>
#include "openprojectdlg4.h"
#include "kscopeconfig4.h"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
OpenProjectDlg::OpenProjectDlg(QWidget* pParent, const char* szName) :
	OpenProjectLayout(pParent, szName)
{
	loadRecent();
	m_pProjPathRequester->setFilter("cscope.proj");
}

/**
 * Class destructor.
 */
OpenProjectDlg::~OpenProjectDlg()
{
}

/**
 * @return	The selected project path
 */
QString OpenProjectDlg::getPath() const
{
	return m_pProjPathRequester->url();
}

/**
 * Sets the requester to reflect the selected project's directory, instead of
 * the cscope.proj file.
 * @param	sProjPath	The full path of the selected cscope.proj file
 */
void OpenProjectDlg::slotProjectSelected(const QString& sProjPath)
{
	QFileInfo fi(sProjPath);
	m_pProjPathRequester->setURL(fi.dirPath(true));
}

/**
 * Removes a project from the recent projects list.
 * This slot is connected to the clicked() signal of the "Remove" button.
 */
void OpenProjectDlg::slotRemoveRecent()
{
	QListBoxItem* pItem;

	// Remove the selected item, if any
	pItem = m_pRecentList->selectedItem();
	if (pItem != NULL) {
		Config().removeRecentProject(pItem->text());
		m_pRecentList->removeItem(m_pRecentList->currentItem());
	}
}

/**
 * Selects a project for opening when an item is highlighted in the recent
 * projects list.
 * This slot is connected to the highlighted() signal of the recent projects
 * list box.
 * @param	pItem	The selected project item
 */
void OpenProjectDlg::slotSelectRecent(QListBoxItem* pItem)
{
	if (pItem != NULL)
		m_pProjPathRequester->setURL(pItem->text());
}

/**
 * Selects a project for opening and closes the dialogue when an item in the
 * recent projects list is double-clicked. 
 * This slot is connected to the doubleClicked() signal of the recent 
 * projects list box.
 * @param	pItem	The selected project item
 */
void OpenProjectDlg::slotOpenRecent(QListBoxItem* pItem)
{
	if (pItem != NULL) {
		m_pProjPathRequester->setURL(pItem->text());
		accept();
	}
}

/**
 * Fills the recent projects list box with the project paths read from the 
 * configuration file.
 */
void OpenProjectDlg::loadRecent()
{
	const QStringList& slProjects = Config().getRecentProjects();
	QStringList::const_iterator itr;

	// Create a list item for each project in the list
	for (itr = slProjects.begin(); itr != slProjects.end(); ++itr)
		m_pRecentList->insertItem(*itr);
}

// #include "openprojectdlg.moc"

// Sat Jul 16 18:50:08 UTC 2011