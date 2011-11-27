#ifndef HISTORYVIEW_H
#define HISTORYVIEW_H

#include "queryview4.h"

/**
 * A list view item for holding position history records.
 * A QListViewItem cannot reference its preceding item, which is required to
 * create a stack-like history list. Therefore a HistoryItem object
 * stores a pointer to the item just above it in the list. The pointer is
 * persistent, since the list cannot be sorted.
 * @author Elad Lahav
 */

class HistoryItem : public QListViewItem
{
public:
	/**
	 * Class constructor.
	 * @param	pList	The parent list view
	 * @param	sFile	The file path in this record
	 * @param	sLine	The line number
	 * @param	sText	The contents of the line in the given file
	 */
	HistoryItem(QListView* pList, QString sFile, QString sLine, 
		QString sText) : 
		QListViewItem(pList, "", sFile, sLine, sText),
		m_pPrevSibling(NULL) {
		HistoryItem* pNext;
		
		// Mark the new item as the predecessor of its next sibling 
		if ((pNext = (HistoryItem*)nextSibling()) != NULL)
			pNext->m_pPrevSibling = this;
	}
	
	/** The item immediately above this one in the list. */
	HistoryItem* m_pPrevSibling;
};

/**
 * A list view widget for holding position history.
 * Position history is kept in a stack-like list. Positions are always added
 * to the top of the list, immediately before the current item. If the
 * current item is not the top one, all items above it are purged first.
 * To keep the stack-like structure, the list cannot be sorted.
 * @author Elad Lahav
 */
class HistoryView : public QueryView
{
Q_OBJECT
public:
	HistoryView(QWidget* pParent = 0, const char* szName = 0);
	~HistoryView();
	
	virtual void addRecord(const QString&, const QString&, const QString&,
		const QString&, QListViewItem*);
	virtual void selectNext();
	virtual void selectPrev();

protected slots:
	virtual void slotRemoveItem(QListViewItem*);
};

#endif
