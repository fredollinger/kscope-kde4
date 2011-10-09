#ifndef GREPDLG_H
#define GREPDLG_H

#include <QDialog>
#include "greplayout.h"

class GrepDlg : public QDialog, public Ui::GrepLayout
{
	Q_OBJECT

public:

	GrepDlg(QWidget* pParent, const char* szName);
	~GrepDlg();
};

#endif

// Sun Oct  9 13:03:15 PDT 2011
