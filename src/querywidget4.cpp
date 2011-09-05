#include <qtoolbutton.h>
#include <qtooltip.h>
#include <klocale.h>
#include <kmessagebox.h>
#include "querywidget4.h"
#include "querypage4.h"
#include "kscopepixmaps4.h"
#include "kscopeconfig4.h"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
QueryWidget::QueryWidget(QWidget* pParent, const char* szName) : Ui::QueryWidgetLayout(),
	// m_pPageMenu(NULL),
	// m_pLockAction(NULL),
	// m_pHistPage(NULL),
	// m_bHistEnabled(true),
	m_nQueryPages(0)
{
	// Pages can be closed by clicking their tabs
	// m_pQueryTabs->setHoverCloseButton(true);
	
	/*
	// Change the lock action state according to the current page
	connect(m_pQueryTabs, SIGNAL(currentChanged(QWidget*)), this,
		SLOT(slotCurrentChanged(QWidget*)));
	
	// Close a query when its tab button is clicked
	connect(m_pQueryTabs, SIGNAL(closeRequest(QWidget*)), this,
		SLOT(slotClosePage(QWidget*)));

	// Show the menu when requested
	connect(m_pQueryTabs, SIGNAL(contextMenu(const QPoint&)), this,
		SLOT(slotContextMenu(const QPoint&)));
	connect(m_pQueryTabs, SIGNAL(contextMenu(QWidget*, const QPoint&)), this,
		SLOT(slotContextMenu(QWidget*, const QPoint&)));
	*/
}

/**
 * Class destructor.
 */
QueryWidget::~QueryWidget()
{
}

/**
 * Runs a query in a query page.
 * A query page is first selected, with a new one created if required. The
 * method then creates a Cscope process and runs the query.
 * @param	nType	The query's numeric type code
 * @param	sText	The query's text, as entered by the user
 * @param	bCase		true for case-sensitive queries, false otherwise
 */
void QueryWidget::initQuery(uint nType, const QString& sText, bool bCase)
{
	QueryPage* pPage;
	
	// Make sure we have a query page
	findQueryPage();
	pPage = (QueryPage*)currentWidget();
			
	// Use the current page, or a new page if the current one is locked
	if (pPage->isLocked()) {
		addQueryPage();
		pPage = (QueryPage*)currentWidget();
	}

	// Reset the page's results list
	pPage->clear();
	pPage->query(nType, sText, bCase);
	
	// Set the page's tab text according to the new query
	// setPageCaption(pPage);
}

/**
 * Ensures the current page is a query page that is ready to accept new
 * queries.
 * The function first checks the current page. If it is an unlocked query
 * page, then nothing needs to be done. Otherwise, it checks for the first
 * unlocked query page by iterating over all pages in the tab widget. If this
 * fails as well, a new query page is created.
 */
void QueryWidget::findQueryPage()
{
	QueryPage* pPage;
	int nPages, i;
	
	// First check if the current page is an unlocked query page
	pPage = dynamic_cast<QueryPage*>(currentWidget());
	if (pPage != NULL) {
		if (!pPage->isLocked() && !pPage->isRunning())
			return;
	}
	
	// Look for the first unlocked query page
	nPages = m_pQueryTabs->count();
	for (i = 0; i < nPages; i++) {
		// pPage = dynamic_cast<QueryPage*>(m_pQueryTabs->page(i));
		pPage = dynamic_cast<QueryPage*>(m_pQueryTabs->widget(i));
		if (pPage != NULL) {
			if (!pPage->isLocked() && !pPage->isRunning()) {
				setCurrentPage(pPage);
				return;
			}
		}
	}

	// Couldn't find an unlocked query page, create a new one
	addQueryPage();
}

/**
 * Creates a new query page, and adds it to the tab widget.
 * The new page is set as the current one.
 */
void QueryWidget::addQueryPage()
{
	QueryPage* pPage;
	QString sTitle;

	// Create the page
	pPage = new QueryPage(this);

	// Add the page, and set it as the current one
	// m_pQueryTabs->insertTab(pPage, GET_PIXMAP(TabUnlocked), "Query",
	//	m_nQueryPages++);
	m_pQueryTabs->insertTab(m_nQueryPages++, pPage, GET_PIXMAP(TabUnlocked), "Query");
	setCurrentPage(pPage);
	
	// Emit the lineRequested() signal when a query record is selected on 
	// this page
	connect(pPage, SIGNAL(lineRequested(const QString&, uint)), this, 
		SLOT(slotRequestLine(const QString&, uint)));
}

// #include "querywidget.moc"
// Fri Sep  2 10:45:05 PDT 2011
