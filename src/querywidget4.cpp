#include <QLocale>
#include <QDockWidget>
#include <QListView>
#include <QString>
#include <QTabWidget>
#include "querywidget4.h"
#include <klocalizedstring.h>

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
QueryWidget::QueryWidget(QWidget* pParent, const char* szName) :
	QDockWidget(i18n(szName), pParent),
	m_nQueryPages(0)
{

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

// Sun Oct  9 14:57:45 PDT 2011
