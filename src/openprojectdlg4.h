#ifndef OPENPROJECTDLG_H
#define OPENPROJECTDLG_H

#include <Q3ListBoxItem>
#include <Q3ListBox>
#include <qwidget.h>
// #include "openprojectlayout4.h"
#include "ui_openprojectdialog2.h"

/**
 * A dialogue for selecting a project to open.
 * Allows projects to be searched, and displays a list of previosuly loaded
 * projects.
 * @author Elad Lahav
 */

// class OpenProjectDlg : public QDialog, public Ui::OpenProjectLayout
class OpenProjectDlg : public QDialog, public Ui::OpenProjectDialog
{
	Q_OBJECT

public: 
	OpenProjectDlg(QWidget* pParent = 0, const char* szName = 0);
	~OpenProjectDlg();

	QString getPath() const;

protected slots:
	virtual void slotProjectSelected(const QString&);
	virtual void slotRemoveRecent();
	virtual void slotSelectRecent(Q3ListBoxItem*);
	virtual void slotOpenRecent(Q3ListBoxItem*);

private:
	void loadRecent();
};

#endif

// Sat Jul 16 18:50:15 UTC 2011
