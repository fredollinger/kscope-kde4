#include "tabwidget4.h"
#include "kscope4.h"

#include <QDebug>
#include <KTabWidget>

TabWidget::TabWidget(QWidget* pParent) :
	KTabWidget(pParent)
{
	connect(this, SIGNAL(closeRequest(QWidget*)),
	this, SLOT(closeClicked(QWidget*)));
}

TabWidget::~TabWidget()
{
}

void TabWidget::closeClicked(QWidget *w){
	// FIXME: Use QStringList
	qDebug()<<"TabWidget::closeClicked";
	emit signalClose(w);
}

// Sat Feb 11 13:13:52 PST 2012
