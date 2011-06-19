#ifndef NEWPROJECTDLG_H
#define NEWPROJECTDLG_H

#include <qlineedit.h>
#include <qcheckbox.h>
#include "newprojectlayout4.h"
#include "autocompletionlayout4.h"
#include "projectbase4.h"
	
/**
 * A sub-dialogue of the New Project dialogue.
 * Allows the user to configure auto-completion parameters.
 * @author Elad Lahav
 */
class AutoCompletionDlg : public QDialog
{
	Q_OBJECT
	
public:
	AutoCompletionDlg(QWidget* pParent, const char* szName = NULL);
	virtual ~AutoCompletionDlg();

public slots:		
protected slots:

private:
	friend class NewProjectDlg;
};

/**
 * A dialog for creating new projects.
 * Prompts the user for the project's name, the directory for Cscope's files,
 * the types of files included in the project and several options.
 * Can also be used to change some of the properties of a project after it
 * has been created.
 * @author Elad Lahav
 */

class NewProjectDlg : public QDialog
{
	Q_OBJECT
	
public: 
	NewProjectDlg(bool, QWidget* pParent = NULL, const char* szName = NULL);
	virtual ~NewProjectDlg();

	QString getName();
	QString getPath();
	void getOptions(ProjectBase::Options&);

protected slots:

private:
	Ui::NewProjectLayout ui;	
	bool m_bNewProj;
};

#endif

// Sun Jun 19 19:47:13 UTC 2011
