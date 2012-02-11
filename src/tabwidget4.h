#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <ktabwidget.h>

/**
 * An extension to the standard KDE tab widget that allows the user to select
 * a tab from a list displayed as a popup menu.
 * @author Elad Lahav
 */
class TabWidget : public KTabWidget
{
Q_OBJECT
public:
	TabWidget(QWidget* pParent = 0);
	~TabWidget();
public slots:
	void closeRequest(int);
};

#endif
// Sat Feb 11 13:14:35 PST 2012
