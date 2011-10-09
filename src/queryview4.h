#ifndef QUERYVIEW_H
#define QUERYVIEW_H

#include <qregexp.h>

#include <QListView>
#include <QWidget>
#include <QObject>

#include "qlistviewitem4.h"

namespace kscope4{
class QueryResultsMenu;

#if 0
class QListViewItem4 : public QObject
{
	Q_OBJECT

public:
	QListViewItem(QListView *pView, QListViewItem *pAfter);
}
#endif
 
/**
 * Items in a query view.
 * The sole purpose for creating a new class is to be able to sort query 
 * results numerically by line number.
 * @author Elad Lahav
 */
// class QueryViewItem : public QListViewItem
class QueryViewItem : public QListViewItem4
{
	Q_OBJECT
public:
	/**
	 * Class constructor.
	 * Used for list views.
	 * @param	pView		The view widget
	 * @param	pAfter		The item to preceed the new one
	 * @param	nLineCol	The index of the line column
	 */
	QueryViewItem(QListView* pView, QListViewItem4* pAfter, 
		int nLineCol) : QListViewItem4(pView, pAfter), m_nLineCol(nLineCol)
		{}
	
	/**
	 * Class constructor.
	 * Used for tree views.
	 * @param	pParent		The parent item
	 * @param	pAfter		The item to preceed the new one
	 * @param	nLineCol	The index of the line column
	 */
	QueryViewItem(QListViewItem4* pParent, QListViewItem4* pAfter, 
		int nLineCol) : QListViewItem4(pParent, pAfter), m_nLineCol(nLineCol)
		{}
	
	/**
	 * Compares two items.
	 * If the given column holds line numbers, than the items are compared
	 * by their numeric values. Otherwise, a standard text comparison is
	 * performed.
	 * @param	pItem	The item to compare to
	 * @param	nCol	The column by which to compare
	 * @param	bAscend	Whether sorting in ascending or descending order
	 * @return	0 if the items are equal, 1 if the current item is greater,
	 * 			-1 if the current item is smaller
	 */
	virtual int compare(QListViewItem4* pItem, int nCol, bool bAscend) const {
		if (nCol == m_nLineCol) {
			uint nLineCur, nLineOther;
			int nResult;

			// Get the line numbers of each item
			// nLineCur = text(nCol).toUInt();
			// nLineOther = pItem->text(nCol).toUInt();

			// Compare the line numbers
			nResult = nLineCur - nLineOther;
			if (nResult == 0)
				return 0; // Items are equal
			else if (nResult > 0)
				return 1; // The first item is greater
			else
				return -1; // The second item is greater
		}
		
		// return QListViewItem::compare(pItem, nCol, bAscend);
		return 0;
	}
	
private:
	/** The index of the column holding the line numbers. */
	int m_nLineCol;
};

/**
 * A list view widget for displaying locations in the source code. Each record
 * (list item) represents a single line of code.
 * The main purpose of this class is for showing query results (@see
 * QueryViewDriver), but is can also serve as a base class for any widget
 * which needs to refer to locations in the source code (@see
 * HistoryView).
 * The view has 4 columns, for showing the file path, function name, line
 * number and line text of a code location.
 * The widget owns a popup menu which allows users to copy information
 * from records, filter records, and more.
 * @author Elad Lahav
 */
class QueryView : public QListView
{
	Q_OBJECT
	
public:
	QueryView(QListView* pParent = 0, const char* szName = 0);
	~QueryView();
	
	virtual void addRecord(const QString&, const QString&, const QString&,
		const QString&, QListViewItem4* pParent = NULL);
	virtual void select(QListViewItem4*);
	virtual void selectNext();
	virtual void selectPrev();
	virtual void queryProgress();
	virtual void queryFinished(uint, QListViewItem4* pParent = NULL);
	
	/**
	 * Provides an iterator over the list of query results.
	 * @author Elad Lahav
	 */
	class Iterator
	{
	public:
		/**
		 * Default constructor.
		 */
		Iterator() : m_pItem(NULL) {}
		
		/**
		 * Copy constructor.
		 * @param	itr	The copied object
		 */
		Iterator(const Iterator& itr) : m_pItem(itr.m_pItem) {}
		
		/**
		 * @return	true if the iterator points _beyond_ the end of the list,
		 *			false otherwise
		 */
		bool isEOF() { return m_pItem == NULL; }
		
		void next();
			
		QString getFunc();
		QString getFile();
		QString getLine();
		QString getText();
		
	private:
		/** Points to the current list item. */
		QListViewItem4* m_pItem;
		
		/** 
		 * Private constructor used to return initialised iterators.
		 * This constructor can only be called from within QueryView.
		 * @param	pItem	The initial list item
		 */
		Iterator(QListViewItem4* pItem) : m_pItem(pItem) {}
		
		friend class QueryView;
	};
	
	Iterator getIterator();
	
signals:
	/**
	 * Notifies the owner widget that it needs to be visible since some
	 * information is available to display.
	 * This information may be an advancement of the progress bar,
	 * availability of query results, etc.
	 */
	void needToShow();
	
	/**
	 * Emitted when a list record is selected. 
	 * Selection is done by either double-clicking a query or by highlighting
	 * it and then pressing the ENTER key.
	 * @param	sFile	The "File" field of the selected record
	 * @param	nLine	The "Line" field of the selected record
	 */
	void lineRequested(const QString& sFile, uint nLine);	
	
protected:	
	/** A popup-menu for manipulating query result items. */
	QueryResultsMenu* m_pQueryMenu;
	
	/** A pointer to the last item (used for appending results). */
	QListViewItem4* m_pLastItem;
	
	void contentsMouseDoubleClickEvent(QMouseEvent*);
	
protected slots:
	virtual void slotRecordSelected(QListViewItem4*);
	virtual void slotFindDef(const QString&);
	virtual void slotCopy(QListViewItem4*, int);
	virtual void slotFilter(int);
	virtual void slotShowAll();
	virtual void slotRemoveItem(QListViewItem4*);
};
}

#endif // QUERYVIEW_H
