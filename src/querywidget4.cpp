#include <QLocale>
#include <QDockWidget>
#include <QListView>
#include <QString>
#include <QTabWidget>
#include "querywidget4.h"
#include "querypage4.h"
#include <klocalizedstring.h>
#include <qdebug.h>

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
QueryWidget::QueryWidget(QWidget* pParent, const char* szName) :
	QDockWidget(i18n(szName), pParent),
	m_nQueryPages(0)
{
	qDebug() << "QueryWidget";
	

	setObjectName("qwFiles");
	m_pQTabWidget = new QTabWidget();

	setWidget(m_pQTabWidget);
	//resDock = new QDockWidget(i18n("Files"), this);

	/*
     customerList = new QListWidget(resDock);
     customerList->addItems(QStringList()
             << "kscope4.h"
             << "main_menu.cpp"
             << "kscope4.cpp");
     resDock->setWidget(customerList);
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
void QueryWidget::initQuery(uint nType __attribute__ ((unused))  , const QString& sText, bool bCase)
{
	// QueryPage* pPage;
	
	// Make sure we have a query page
	// findQueryPage();
	// pPage = (QueryPage*)currentPage();
			
	// Use the current page, or a new page if the current one is locked
	/*
	if (pPage->isLocked()) {
		addQueryPage();
		// pPage = (QueryPage*)currentPage();
	}
	*/

	// Reset the page's results list
	// pPage->clear();
	// pPage->query(nType, sText, bCase);
	
	// Set the page's tab text according to the new query
	// setPageCaption(pPage);
}

/**
 * Applies the user's colour and font preferences to all pages.
 */
void QueryWidget::applyPrefs()
{
	qDebug() << "QueryWidget::applyPrefs(): FIXME not implemented";
	// QueryPage* pPage;
	QString sTitle;

	return;
#if 0
	QueryPage* pPage;
	int nPages, i;

	// Iterate query pages
	nPages = m_pQueryTabs->count();
	for (i = 0; i < nPages; i++) {
		pPage = (QueryPage*)m_pQueryTabs->page(i);
		pPage->applyPrefs();
		setPageCaption(pPage);
	}
#endif
}

#if 0
/**
 * Loads all pages saved when the project was closed.
 * @param	sProjPath		The full path of the project directory
 * @param	slFiles	The list of query file names to load
 */
void QueryWidget::loadPages(const QString& sProjPath,
	const QStringList& slFiles)
{

	qDebug() << "QueryWidget::loadPages(): FIXME not implemented";
	QStringList::ConstIterator itr;
	QueryPageBase* pPage;
	QString sName;
	
	// Iterate through query files
	for (itr = slFiles.begin(); itr != slFiles.end(); ++itr) {
		// Set the target page, based on the file type (query or history)
		if ((*itr).startsWith("History")) {
			findHistoryPage();
			pPage = m_pHistPage;
		}
		else {
			findQueryPage();
			pPage = (QueryPage*)currentPage();
		}

		// Load a query file to this page, and lock the page
		if (pPage->load(sProjPath, *itr)) {
			setPageCaption(pPage);
			setPageLocked(pPage, true);
		}
	}
}

/**
 * Stores all pages marked for saving into files in the project directory.
 * @param	sProjPath		The full path of the project directory
 * @param	slFiles			Holds a list of query file names, upon return
 */
void QueryWidget::savePages(const QString& sProjPath, QStringList& slFiles)
{
	int nPageCount, i;
	QueryPage* pPage;
	QString sFileName;
	
	// Iterate pages
	nPageCount = m_pQueryTabs->count();
	for (i = 0; i < nPageCount; i++) {
		pPage = (QueryPage*)m_pQueryTabs->page(i);
		if (pPage->shouldSave()) {
			// Store this query page
			if (pPage->save(sProjPath, sFileName) && !sFileName.isEmpty())
				slFiles.append(sFileName);
		}
	}
}

/**
 * Adds a new position record to the active history page.
 * @param	sFile	The file path
 * @param	nLine	The line number
 * @param	sText	The contents of the line pointed to by the file path and
 * 					line number
 */
void QueryWidget::addHistoryRecord(const QString& sFile, uint nLine, 
	const QString& sText)
{
	// Validate file name and line number
	if (sFile.isEmpty() || nLine == 0)
		return;
	
	// Do nothing if history logging is disabled
	if (!m_bHistEnabled)
		return;

	// Make sure there is an active history page	
	findHistoryPage();
			
	// Add the position entry to the active page
	m_pHistPage->addRecord(sFile, nLine, sText);
}

/**
 * Sets the tab caption and tool-tip for the given page.
 * @param	pPage	The page whose tab needs to be changed
 */
void QueryWidget::setPageCaption(QueryPageBase* pPage)
{
	m_pQueryTabs->changeTab(pPage, 
		pPage->getCaption(Config().getUseBriefQueryCaptions()));
	m_pQueryTabs->setTabToolTip(pPage, pPage->getCaption());
}

/**
 * Creates a new query page, and adds it to the tab widget.
 * The new page is set as the current one.
 */
void QueryWidget::addQueryPage()
{
	qDebug() << "BEGIN QueryWidget::addQueryPage()";
	// QueryPage* pPage;
	QString sTitle;

	return;
/*
	// Create the page
	pPage = new QueryPage(this);

	// Add the page, and set it as the current one
	m_pQueryTabs->insertTab(pPage, GET_PIXMAP(TabUnlocked), "Query",
		m_nQueryPages++);
	setCurrentPage(pPage);
	
	// Emit the lineRequested() signal when a query record is selected on 
	// this page
	// connect(pPage, SIGNAL(lineRequested(const QString&, uint)), this, 
		//SLOT(slotRequestLine(const QString&, uint)));
}
*/

void QueryWidget::newQueryPage()
	return;
}

void QueryWidget::bob(){
	return;
}

#endif
// Sat Nov 26 09:48:44 PST 2011
