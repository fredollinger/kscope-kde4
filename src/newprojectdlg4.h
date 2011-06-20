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

class NewProjectDlg : public QDialog, public Ui::NewProjectLayout
{
	Q_OBJECT
	
public: 
	NewProjectDlg(bool, QWidget* pParent = NULL, const char* szName = NULL);
	// NewProjectDlg(void);
	~NewProjectDlg();

	void setProperties(const QString&, const QString&, 
		const ProjectBase::Options&);

	QString getName();
	QString getPath();
	void getOptions(ProjectBase::Options&);

protected slots:
	void accept();
	void reject();
	void slotAddType();
	void slotRemoveType();
	void slotAvailTypesChanged(const QString&);

private:
	/** The file MIME-types associated with the new project. */
	QStringList m_slTypes;

	bool m_bNewProj;
};

#endif

// Mon Jun 20 19:44:45 UTC 2011
