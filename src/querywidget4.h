#ifndef QUERYWIDGET_H
#define QUERYWIDGET_H

#include <QMenu>
#include <qlistview.h>
// #include <qpopupmenu.h>
#include <kaction.h>
#include "querywidgetlayout4.h"
// #include "tabwidget4.h"
#include "querypage4.h"
#include "querypagebase4.h"
// #include "historypage4.h"
// #include "projectmanager4.h"
#include <QDialog>

/**
 * A tabbed-window holding Cscope query results pages.
 * @author Elad Lahav
*/

class QueryWidget : public QDialog , public Ui::QueryWidgetLayout
{
   Q_OBJECT

public:
	QueryWidget(QWidget* pParent = 0, const char* szName = 0);
	~QueryWidget();

	void addQueryPage();
	void initQuery(uint, const QString&, bool);
	void applyPrefs();
	void loadPages(const QString&, const QStringList&);
	void savePages(const QString&, QStringList&);
	void addHistoryRecord(const QString&, uint, const QString&);
	void selectActiveHistory();
	// void setPageMenu(QMenu*, KToggleAction*);
	// void getBookmarks(FileLocationList&);
	
	/**
	 * Enables/disables new history items.
	 * @param	bEnabled	true to enable new history items, false to 
	 *						disable
	 */
	// void setHistoryEnabled(bool bEnabled) { m_bHistEnabled = bEnabled; }

/*
public slots:
	void slotNewQueryPage();
	void slotLockCurrent(bool);
	void slotLockCurrent();
	void slotRefreshCurrent();
	void slotNextResult();
	void slotPrevResult();
	void slotCloseCurrent();
	void slotCloseAll();
	void slotHistoryPrev();
	void slotHistoryNext();
*/
	
signals:
	/**
 	 * Emitted when the a lineRequested() signal is received from any of the
	 * currently open query pages. 
	 * @param	sPath	The full path of the requested source file
	 * @param	nLine	The requested line number
	 */
	void lineRequested(const QString& sPath, uint nLine);
	
	/**
	 * Emitted when new query page is requested by user
	 */
	void newQuery();
	
private:
	/** A popup menu with query page commands (new query, lock/unlock, close
		query, etc.). */
	QMenu* m_pPageMenu;
	
#if 0
	/** A toggle-like action for changing the locked state of a query. */
	// KToggleAction* m_pLockAction;
	
	/** The active history page. */
	// HistoryPage* m_pHistPage;
	
	/** Determines whether history items should be added to the active
		history page. */
	bool m_bHistEnabled;
	
	/** The number of query pages currently open. */
	int m_nQueryPages;
	
	void setPageCaption(QueryPageBase*);
	
	/**
	 * @return	The active page in the tab widget
	 */
	inline QueryPageBase* currentWidget()	{ 
		return (QueryPageBase*)m_pQueryTabs->currentWidget();
	}
	
	/**
	 * @param	pWidget	A query page to set as the current one
	 */

	inline void setCurrentPage(QWidget* pWidget) {
		if (pWidget)
			m_pQueryTabs->setCurrentPage(m_pQueryTabs->indexOf(pWidget));
	}

	inline bool isHistoryPage(QWidget* pPage) {
		return (dynamic_cast<HistoryPage*>(pPage) != NULL);
	}
#endif
	/**
	 * @return	The active page in the tab widget
	 */
	inline QueryPageBase* currentWidget()	{ 
		return (QueryPageBase*)m_pQueryTabs->currentWidget();
	}
	// void setPageLocked(QueryPageBase*, bool);
	void findQueryPage();
	void findHistoryPage();

/*
private slots:
	void slotRequestLine(const QString&, uint);
	void slotCurrentChanged(QWidget*);
	void slotClosePage(QWidget*);
	void slotContextMenu(const QPoint&);
	void slotContextMenu(QWidget*, const QPoint&);
*/
};

#endif
// Sun Sep  4 13:51:43 PDT 2011
