#include "tabwidget4.h"
#include "kscope4.h"

#include <QDebug>
#include <KTabWidget>

TabWidget::TabWidget(QWidget* pParent) :
	KTabWidget(pParent)
{
	// connect (this, closeRequest(int), pParent, slotCloseTab(int));
}

TabWidget::~TabWidget()
{
}

void TabWidget::closeRequest(int i)
{
	qDebug()<<"closeRequest: "<<i;
}
// Sat Feb 11 13:13:52 PST 2012
