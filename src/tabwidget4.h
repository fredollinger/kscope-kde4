#ifndef TABWIDGET_H
#define TABWIDGET_H


#include <qtoolbutton.h>
#include "kspopup.h"
#include <ktabwidget.h>

/**
 * An extension to the standard KDE tab widget that allows the user to select
 * a tab from a list displayed as a popup menu.
 * @author Elad Lahav
 */
namespace kscope4{
class TabWidget : public KTabWidget
{
Q_OBJECT
public:
    TabWidget(QWidget* pParent = 0, const char* szName = 0);
    ~TabWidget();

private:
	/** The list button. */
	QToolButton* m_pButton;
	
	/** A popup-menu containing all tab labels. */
	KSPopup * m_pMenu;
	
private slots:
	void slotShowTabList();
};
}// namespace kscope4

#endif
