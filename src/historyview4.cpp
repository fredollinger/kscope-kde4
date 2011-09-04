#include "historyview4h"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
HistoryView::HistoryView(QWidget* pParent, const char* szName) :
	QueryView(pParent, szName)
{
	// Disable sorting
	setSortColumn(-1);
	
	// Don't show the "Function" column
	setColumnWidthMode(0, QListView::Manual);
	setColumnWidth(0, 0);
}

/**
 * Class destructor.
 */
HistoryView::~HistoryView()
{
}

/**
 * Creates a new list item showing a history record.
 * @param	sFunc	The name of the function
 * @param	sFile	The file path
 * @param	sLine	The line number in the above file
 * @param	sText	The line's text
 */
void HistoryView::addRecord(const QString& /* sFunc */, const QString& sFile,
	const QString& sLine, const QString& sText, QListViewItem*)
{
	HistoryItem* pItem;
	
	pItem = new HistoryItem(this, sFile, sLine, sText);
	setSelected(pItem, true);
}

/**
 * Moves to the previous item in the history, selecting it for display.
 * Note that this function move to the item which chronologically precedes
 * the current one, which, in list view terms, is the next item.
 */
void HistoryView::selectPrev()
{
	QListViewItem* pItem;

	// Get the current item
	pItem = currentItem();
	
	// Select the next item in the list
	if (pItem != NULL && pItem->nextSibling() != NULL) {
		pItem = pItem->nextSibling();
		select(pItem);
	}
}

/**
 * Moves to the next item in the history, selecting it for display.
 * Note that this function move to the item which chronologically succedes
 * the current one, which, in list view terms, is the previous item.
 */
void HistoryView::selectNext()
{
	HistoryItem* pItem;

	// Get the current item
	pItem = (HistoryItem*)currentItem();
	
	// Select the previous item in the list
	if (pItem != NULL && pItem->m_pPrevSibling != NULL) {
		pItem = pItem->m_pPrevSibling;
		select(pItem);
	}
}

/**
 * Deletes the item on which a popup-menu has been invoked.
 * This slot is connected to the remove() signal of the QueryResultsMenu
 * object.
 * @param	pItem	The item to remove
 */
void HistoryView::slotRemoveItem(QListViewItem* pItem)
{
	HistoryItem* pCurItem, * pNextItem;
	
	pCurItem = (HistoryItem*)pItem;
	if ((pNextItem = (HistoryItem*)pCurItem->nextSibling()) != NULL)
		pNextItem->m_pPrevSibling = pCurItem->m_pPrevSibling;
	
	delete pCurItem;
}

// #include "historyview.moc"
