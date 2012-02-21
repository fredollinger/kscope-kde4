#include <QMenu>
#include "kspopup.h"


namespace kscope4{

// BEGIN CONSTRUCTOR
KSPopup::KSPopup(QWidget* pParent, const char * szName) : QMenu(pParent)
{
}
// END CONSTRUCTOR

// BEGIN DESTRUCTOR
KSPopup::~KSPopup()
{
}
// END DESTRUCTOR

void KSPopup::removeItem(int i){
}

void KSPopup::insertItem(QString qs, int i){
}

} // namespace kscope4
// Mon Feb 20 08:58:07 PST 2012
#if 0
editortabs4.cpp:	m_pWindowMenu = pWindowMenu;
editortabs.cpp:		m_pWindowMenu->removeItem(i);
editortabs.cpp:		m_pWindowMenu->insertItem(sLabel, i);
#endif
