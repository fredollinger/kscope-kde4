#ifndef K_DOCK_WIDGET_H
#define K_DOCK_WIDGET_H

#include <QSystemTrayIcon>

class KDockWidget : public QSystemTrayIcon
{
public: 
	KDockWidget();
	virtual ~KDockWidget();
	void changeHideShowState(void);
};

#endif
