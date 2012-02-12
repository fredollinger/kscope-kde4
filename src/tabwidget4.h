#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <ktabwidget.h>
#include <KUrl>


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
	KUrl getName(int i);
	void setName(int i, KUrl);
signals:	
	void signalClose(QWidget *w);
public slots:
	void closeClicked(QWidget *w);
private:
	KUrl m_kuName;
};

#endif
// Sat Feb 11 13:14:35 PST 2012

