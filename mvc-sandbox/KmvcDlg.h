#ifndef KMVC_DLG_H
#define KMVC_DLG_H

#include <QMainWindow>

#include "kmvcwindow.h"

class KmvcDlg : public QMainWindow, public Ui::KmvcLayout
{
	Q_OBJECT
public:
	KmvcDlg(QWidget* pParent = NULL, const char* szName = NULL);
	~KmvcDlg();
};
	

#endif 
// Sun Sep 25 09:32:46 PDT 2011
