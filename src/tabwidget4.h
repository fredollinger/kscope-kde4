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
    TabWidget(QWidget* pParent = 0, const char* szName = 0);
    ~TabWidget();

};

#endif
// Fri Feb 10 09:31:31 PST 2012
