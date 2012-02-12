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

KUrl TabWidget::getName(int i){
	// FIXME: Use QStringList b/c of many tabs
	return m_kuName;
}

void TabWidget::setName(int i, KUrl ku){
	m_kuName = ku;
	setTabText(i, ku.pathOrUrl());
}

// Sat Feb 11 13:13:52 PST 2012
