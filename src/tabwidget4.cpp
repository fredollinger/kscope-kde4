#include <qtooltip.h>
#include <klocale.h>
#include "tabwidget4.h"
// #include "kscopepixmaps.h"
#include "kspopup.h"

/**
 * Class constructor.
 * @param	pParent	A pointer to the parent widget
 * @param	szName	Optional widget name
 */
namespace kscope4{
TabWidget::TabWidget(QWidget* pParent, const char* szName) :
	KTabWidget(pParent)
{
	// Create a popup menu
	m_pMenu = new KSPopup(this);
	
	// Set the current tab based on the menu selection
	connect(m_pMenu, SIGNAL(activated(int)), this, SLOT(setCurrentPage(int)));
	
	// Create a button at the top-right corner of the tab widget
	m_pButton = new QToolButton(this);
	// m_pButton->setIconSet(Pixmaps().getPixmap(KScopePixmaps::TabList));
	// QToolTip::add(m_pButton, i18n("Shows a list of all open tabs"));
	m_pButton->adjustSize();
	setCornerWidget(m_pButton, Qt::TopRightCorner);
	
	// Show the popup-menu when the button is clicked
	connect(m_pButton, SIGNAL(clicked()), this, SLOT(slotShowTabList()));
}

/**
 * Class destructor.
 */
TabWidget::~TabWidget()
{
}

/**
 * Creates and displays a popup-menu containing all tab labels.
 * This slot is connected to the clicked() signal emitted by the list button.
 */
void TabWidget::slotShowTabList()
{
	int i;
	
	// Delete the previous menu
	m_pMenu->clear();

	// Create and populate the menu	
	for (i = 0; i < count(); i++)
		m_pMenu->insertItem(tabText(i), i);
		
	// Show the menu
	m_pMenu->popup(mapToGlobal(m_pButton->pos()));
}

QWidget* TabWidget::page(int i) const{
	return widget(i);
}

} // namespace kscope4
