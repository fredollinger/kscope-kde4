#include <QLocale>
#include <QDockWidget>
#include <QListView>
#include <QString>
#include <QTabWidget>
#include "querywidget4.h"
#include "querypage4.h"
#include "queryview4.h"
#include <klocalizedstring.h>
#include <qdebug.h>

void QueryWidget::addQueryPage()
{
	qDebug() << "QueryWidget::initQuery";
	QueryPage* pPage;
	const QString sTitle = "Query";

	// Create the page
	pPage = new QueryPage(this, "Query");
	return;

	qDebug() << "QueryWidget::addTab";
	// m_pQueryTabs->addTab(pPage, sTitle);

	// Add the page, and set it as the current one
	//m_pQueryTabs->insertTab(pPage, GET_PIXMAP(TabUnlocked), "Query",
		//m_nQueryPages++);
	#if 0
	setCurrentPage(pPage);
	
	// Emit the lineRequested() signal when a query record is selected on 
	// this page
	connect(pPage, SIGNAL(lineRequested(const QString&, uint)), this, 
		SLOT(slotRequestLine(const QString&, uint)));
	#endif

}

/*!
 * QueryWidget is the manager for all queries. 
 * It maintains all the specialized functions for the list view model.
 * The actual model is QueryView while QueryPage and QueryPageBase
 * runs the show on queries.
 * 
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

void QueryWidget::initQuery(uint nType, const QString& sText, bool bCase)
{
	qDebug() << "QueryWidget::initQuery";
	QueryPage* pPage;
	return;
	// addQueryPage();

	qDebug() << "QueryWidget::initQuery(): pPage = (QueryPage*)currentPage()";
	// pPage = (QueryPage*)currentPage();
	// Reset the page's results list
	// pPage->clear();
	// pPage->query(nType, sText, bCase);
}

// Sat Nov 26 09:48:44 PST 2011
