#include <qtoolbutton.h>
#include <qtooltip.h>
#include <klocale.h>
#include <kmessagebox.h>
#include "querywidget4.h"
#include "kscopepixmaps4.h"
#include "kscopeconfig4.h"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
QueryWidget::QueryWidget(QWidget* pParent, const char* szName) : Ui::QueryWidgetLayout()
	// m_pPageMenu(NULL),
	// m_pLockAction(NULL),
	// m_pHistPage(NULL),
	// m_bHistEnabled(true),
	// m_nQueryPages(0)
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

// #include "querywidget.moc"
// Fri Sep  2 10:45:05 PDT 2011
