#include <qapplication.h>
#include <qclipboard.h>
#include <klocale.h>
#include <QStringListModel>

#include "cscopefrontend4.h"
#include "qtableviewitem4.h"
#include "queryview4.h"

#include <QObject>

QueryView::QueryView(QWidget* pParent, const char* szName) : QStringListModel()
{

}

QueryView::~QueryView(){
}
// Sat Dec 24 18:39:08 PST 2011
