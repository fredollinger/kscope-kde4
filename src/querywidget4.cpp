#include <QLocale>
#include <QDockWidget>
#include <QListView>
#include <QString>
#include "querywidget4.h"
#include <klocalizedstring.h>

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
namespace kscope4{
QueryWidget::QueryWidget(QWidget* pParent, const char* szName) :
	QDockWidget(i18n(szName), pParent),
	m_nQueryPages(0)
{

#if 0
/home/follinge/projects/kscope-kde4/src/querywidget4.cpp :17:47: error: no matching function for call to ‘QDockWidget::QDockWidget(QString, kscope4::QueryWidget* const)’
/usr/include/qt4/QtGui/qdockwidget.h:128:5: note: candidates are: QDockWidget::QDockWidget(const QDockWidget&)
/usr/include/qt4/QtGui/qdockwidget.h:73:14: note:                 QDockWidget::QDockWidget(QWidget*, Qt::WindowFlags)
/usr/include/qt4/QtGui/qdockwidget.h:72:14: note:                 QDockWidget::QDockWidget(const QString&, QWidget*, Qt::WindowFlags)
#endif

	/*
	resDock = new QDockWidget(i18n("Files"), this);

     resDock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
     customerList = new QListWidget(resDock);
     customerList->addItems(QStringList()
             << "kscope4.h"
             << "main_menu.cpp"
             << "kscope4.cpp");
     resDock->setWidget(customerList);
     addDockWidget(Qt::BottomDockWidgetArea, resDock);
	*/

}

/**
 * Class destructor.
 */
QueryWidget::~QueryWidget()
{
}

} // namespace kscope4
// Sun Oct  9 14:57:45 PDT 2011
