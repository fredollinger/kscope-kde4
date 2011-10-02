#ifndef KMVC_DLG_H
#define KMVC_DLG_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>

#include "kmvcwindow.h"
#include "grepfrontend.h"

class KmvcDlg : public QMainWindow, public Ui::KmvcLayout
{
	Q_OBJECT
public:
	KmvcDlg(QWidget* pParent = NULL, const char* szName = NULL);
	~KmvcDlg();
private:
	QStringList m_list;
	QStringListModel *m_model;
	GrepFrontend *gfe;
private slots:
	void slotLs(void);

};
	

#endif 
// Sun Sep 25 09:32:46 PDT 2011
