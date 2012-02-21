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

void KSPopup::clear(){
}

void KSPopup::popup(QPoint qp){
}



} // namespace kscope4
// Mon Feb 20 08:58:07 PST 2012
