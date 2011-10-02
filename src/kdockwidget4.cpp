#include "kdockwidget4.h"

KDockWidget::KDockWidget() 
{
}

KDockWidget::~KDockWidget()
{
}

void KDockWidget::changeHideShowState()
{
	if (isVisible()){
		setVisible(false);
	}
	else{
		setVisible(true);
	}
}
