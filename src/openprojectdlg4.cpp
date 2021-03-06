#include <qpushbutton.h>
#include <qlineedit.h>
#include <kurlrequester.h>
#include <qdebug.h>

#include "ui_openprojectdialog2.h"
#include "openprojectdlg4.h"
#include "kscopeconfig4.h"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
OpenProjectDlg::OpenProjectDlg(QWidget* pParent, const char* szName) :
	Ui::OpenProjectDialog()
//	Ui::OpenProjectLayout()
{
	setupUi(this);

	qDebug() << "OpenProjectDlg::OpenProjectDlg: init(): FIXME";

	loadRecent();

	// m_pProjPathRequester->setFilter("cscope.proj");
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
    	return pathEdit_->text();
}

void OpenProjectDlg::accept(){
	qDebug() << "OpenProjectDlg::slot accept: " << pathEdit_->text();
	QDialog::accept();
}

void OpenProjectDlg::recentProjectSelected(){
	qDebug() << "OpenProjectDlg::slotProjectSelected: FIXME";

        // QListWidgetItem* item = m_pRecentList->selectedItems().first();
        openButton_->setEnabled(true);
    	removeProjectButton_->setEnabled(true);
	pathEdit_->setText(m_pRecentList->currentItem()->text());
	 //pathEdit_->setText("bob");
}

/**
 * Sets the requester to reflect the selected project's directory, instead of
 * the cscope.proj file.
 * @param	sProjPath	The full path of the selected cscope.proj file
 */
void OpenProjectDlg::slotProjectSelected(const QString& sProjPath)
{
	QFileInfo fi(sProjPath);

}

// BEGIN DEPRECATED
/**
 * Removes a project from the recent projects list.
 * This slot is connected to the clicked() signal of the "Remove" button.
 */
void OpenProjectDlg::slotRemoveRecent()
{
	// QListWidgetItem *pItem;

	// Remove the selected item, if any
	/*
	pItem = m_pRecentList->selectedItem();
	if (pItem != NULL) {
		Config().removeRecentProject(pItem->text());
		m_pRecentList->removeItem(m_pRecentList->currentItem());
	}
	*/
}
// END DEPRECATED

/**
 * Selects a project for opening when an item is highlighted in the recent
 * projects list.
 * This slot is connected to the highlighted() signal of the recent projects
 * list box.
 * @param	pItem	The selected project item
 */
void OpenProjectDlg::slotSelectRecent(QListWidgetItem *pItem)
{
	qDebug() << "OpenProjectDlg::slotSelectRecent: FIXME";
	// if (pItem != NULL)
		// m_pProjPathRequester->setUrl(pItem->text());
}

/**
 * Selects a project for opening and closes the dialogue when an item in the
 * recent projects list is double-clicked. 
 * This slot is connected to the doubleClicked() signal of the recent 
 * projects list box.
 * @param	pItem	The selected project item
 */
void OpenProjectDlg::slotOpenRecent(QListWidgetItem* pItem)
{
	// if (pItem != NULL) {
		// m_pProjPathRequester->setUrl(pItem->text());
//		accept();
//	}
}

/**
 * Fills the recent projects list box with the project paths read from the 
 * configuration file.
 */
void OpenProjectDlg::loadRecent()
{
	const QStringList& slProjects = kscope4::Config().recentProjects();
	// QStringList::const_iterator itr;
	QStringListIterator itr(slProjects);

	// Create a list item for each project in the list
	while (itr.hasNext())
		m_pRecentList->addItem(itr.next());
}


void OpenProjectDlg::removeProject(){
	QListWidgetItem *pItem;

	// Remove the selected item, if any
	pItem = m_pRecentList->currentItem();
	if (pItem != NULL) {
		kscope4::Config().removeProject(pItem->text());
		m_pRecentList->takeItem(m_pRecentList->currentRow());
	}
	return;
}
// Sun Dec  4 09:30:23 PST 2011
