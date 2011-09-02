#include "calltreemanager4.h"
#include "calltreedlg4.h"
#include "projectmanager4.h"
#include <qdebug.h>

/**
 * Class constructor.
 * @param	pParent	The widget to use as the parent of all Call Tree 
  *					dialogues
 */
CallTreeManager::CallTreeManager(QWidget* pParent) : QObject(pParent)
{
	// Delete dialogue objects when they are removed from the list
	// m_lstDialogs.setAutoDelete(true);
	qDebug() << "CallTreeManager::CallTreeManager FIXME: We need to delete all when the list is deleted!\n";
}

/**
 * Class destructor.
 */
CallTreeManager::~CallTreeManager()
{
	// delete all the items in the list when we are destroyed...
	// qDeleteAll();
}

/** 
 * Saves all call trees into the project directory.
 * @param	sProjPath	The project's directory
 * @param	slFiles		Holds a list of saved file names, upon return
 */
void CallTreeManager::saveOpenDialogs(const QString& sProjPath,
	QStringList& slFiles)
{
	CallTreeDlg *pDlg;
	
	// Iterate over the open dialogues
	/*
	for (pDlg = m_lstDialogs.first(); pDlg != NULL; 
		pDlg = m_lstDialogs.next()) {
		pDlg->store(sProjPath);
		slFiles += pDlg->getFileName();
	}
	I REIMPLEMENT THIS SO:
	*/
	for (int i = 0; i < m_lstDialogs.size(); ++i) {
		pDlg = m_lstDialogs.at(i);
		pDlg->store(sProjPath);
		slFiles += pDlg->getFileName();
	}
}

/** 
 * Loads all call trees according to the list of files 
 * @param	sProjPath	The project's directory
 * @param	slFiles		A list of file names to open
 */
void CallTreeManager::loadOpenDialogs(const QString& sProjPath,
	const QStringList& slFiles)
{
	QStringList::ConstIterator itr;
	CallTreeDlg *pDlg;
	
	int i=-1;
	for (itr = slFiles.begin(); itr != slFiles.end(); ++itr) {
		i++;
		// Create a new dialogue for this file
		pDlg = addDialog();
		
		// Try to load the graph from the file
		if (!pDlg->load(sProjPath, *itr)) {
			// m_lstDialogs.remove(pDlg);
			m_lstDialogs.removeAt(i);
			continue;
		}
		
		// Show the call tree
		pDlg->show();
	}
}

/** 
 * Creates a new Call Tree dialogue.
 * @return	The newly allocated dialogue object
 */
CallTreeDlg* CallTreeManager::addDialog() 
{
	CallTreeDlg* pDlg;
	
	// Create a modeless call tree dialogue
	pDlg = new CallTreeDlg();
	m_lstDialogs.append(pDlg); 
	
	// Open an editor whenever a function name is double-clicked
	connect(pDlg, SIGNAL(lineRequested(const QString&, uint)),
		this, SIGNAL(lineRequested(const QString&, uint)));

	// Track the closing of the call tree dialog
	connect(pDlg, SIGNAL(closed(const CallTreeDlg*)), this,
		SLOT(slotRemoveDialog(const CallTreeDlg*)));
	
	return pDlg;
}

/** 
 * Closes all Call Tree dialogues.
 */
void CallTreeManager::closeAll()
{
	m_lstDialogs.clear();
}

/** 
 * Removes a Call Tree dialogue from the list of open Call Trees.
 * This slot is connected to the closed() signal emitted by the dialogue.
 * @param	pDlg	The dialogue to remove from the list
 */
void CallTreeManager::slotRemoveDialog(const CallTreeDlg* pDlg) 
{
	qDebug() << "CallTreeManager::slotRemoveDialog: FIXME: IMPLEMENT!\n";
	// m_lstDialogs.remove(pDlg);
}

// #include "calltreemanager.moc"

// Thu Sep  1 16:40:13 PDT 2011
