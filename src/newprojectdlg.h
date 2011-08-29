#ifndef NEWPROJECTDLG_H
#define NEWPROJECTDLG_H

#include <qlineedit.h>
#include <qcheckbox.h>
#include <newprojectlayout.h>
#include <autocompletionlayout.h>
#include "projectbase4.h"
	
/**
 * A sub-dialogue of the New Project dialogue.
 * Allows the user to configure auto-completion parameters.
 * @author Elad Lahav
 */
class AutoCompletionDlg : public AutoCompletionLayout

{
	Q_OBJECT
	
public:
	AutoCompletionDlg(QWidget* pParent, const char* szName = NULL);
	~AutoCompletionDlg();
	void getOptions(ProjectBase::Options&);

public slots:		
	int exec();
	
protected slots:
	virtual void accept();

private:

	/** The minimum number of characters in a symbol required for automatic
		completion. */
	uint m_nMinChars;
	
	/** The time, in seconds, to wait before automatic completion is
		attempted. */
	uint m_nDelay;
	
	/** The maximal number of results. */
	uint m_nMaxEntries;

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

class NewProjectDlg : public NewProjectLayout
{
	Q_OBJECT
	
public: 
	NewProjectDlg(bool, QWidget* pParent = NULL, const char* szName = NULL);
	~NewProjectDlg();
	
	void setProperties(const QString&, const QString&, 
		const ProjectBase::Options&);

	QString getName();
	QString getPath();
	void getOptions(ProjectBase::Options&);
	
protected slots:
	virtual void accept();
	virtual void slotAddType();
	virtual void slotRemoveType();
	virtual void slotAvailTypesChanged(const QString&);

private:
	/** The file MIME-types associated with the new project. */
	QStringList m_slTypes;
	
	/** A sub-dialogue for configuring symbol auto-completion parameters. */
	AutoCompletionDlg* m_pAutoCompDlg;
	
	/** Whether the dialogue represents a new or existing project. */
	bool m_bNewProj;
};

#endif
