#include <qdebug.h>
#include <QRegExp>
#include <qregexp.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <kurlrequester.h>
#include <klineedit.h>
#include <kmessagebox.h>
#include <klocale.h>
#include "newprojectdlg4.h"
#include "autocompletionlayout4.h"

NewProjectDlg::NewProjectDlg(bool bNewProj, QWidget* pParent, 
	const char* szName) :
	Ui::NewProjectLayout(),
	m_bNewProj(bNewProj)
{
	setupUi(this);

	// BEGIN OLD STUFF
	ProjectBase::Options opt;

	// FIXME:
	// Create the auto-completion sub-dialogue
	// m_pAutoCompDlg = new AutoCompletionDlg(this);
	
	// Restrict the path requester to existing directories.
	/*
	m_pPathRequester->setMode(KFile::Directory | KFile::ExistingOnly | 
		KFile::LocalOnly);
	m_pSrcRootRequester->setMode(KFile::Directory | KFile::ExistingOnly | 
			KFile::LocalOnly);
	*/
	
	// Set up the Create/Cancel buttons	
	// connect(this->m_pCreateButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(Ui::NewProjectLayout::m_pCancelButton, SIGNAL(clicked()), this, SLOT(reject()));

	// FIXME:
	// Show the auto-completion properties dialogue
	// connect(m_pACButton, SIGNAL(clicked()), m_pAutoCompDlg, SLOT(exec()));	
		
	// FIXME:
	// Perform actions specific to the type of dialog (new project or
	// project properties)
	/*
	if (bNewProj) {
		// Set default project properties
		ProjectBase::getDefOptions(opt);
		setProperties("", "", opt);
	}
	else {
		// Give appropriate titles to the dialog and the accept button
		setCaption(i18n("Project Properties"));
		m_pCreateButton->setText(i18n("OK"));
		
		// Disable the non-relevant widgets
		m_pNameEdit->setEnabled(false);
		m_pPathRequester->setEnabled(false);
	}
	*/

	// END OLD STUFF
}

NewProjectDlg::~NewProjectDlg()
{
}


/**
 * Fills a structure with all user-configured project options.
 * @param	opt	The structure to fill
 */
void NewProjectDlg::getOptions(ProjectBase::Options& opt)
{
	/*
	opt.sSrcRootPath = m_pSrcRootRequester->url();
	opt.slFileTypes = m_slTypes;
	opt.bKernel = m_pKernelCheck->isChecked();
	opt.bInvIndex = m_pInvCheck->isChecked();
	opt.bNoCompress = m_pNoCompCheck->isChecked();
	opt.bSlowPathDef = m_pSlowPathCheck->isChecked();
		
	if (m_pAutoRebuildCheck->isChecked())
		opt.nAutoRebuildTime = m_pAutoRebuildSpin->value();
	else
		opt.nAutoRebuildTime = -1;
		
	if (m_pTabWidthCheck->isChecked())
		opt.nTabWidth = m_pTabWidthSpin->value();
	else
		opt.nTabWidth = 0;
		
	opt.bACEnabled = m_pACCheck->isChecked();
	opt.nACMinChars = m_pAutoCompDlg->m_nMinChars;
	opt.nACDelay = m_pAutoCompDlg->m_nDelay;
	opt.nACMaxEntries = m_pAutoCompDlg->m_nMaxEntries;
	
	opt.sCtagsCmd = m_pCtagsCmdEdit->text();
	*/
}

/**
 * Retrieves the text entered by the user in the dialog's "Project Name" edit
 * box.
 * @return	The name of the new project
 */
/*
QString NewProjectDlg::getName()
{
	return m_pNameEdit->text();
}
*/

/**
 * Retrieves the text entered by the user in the dialog's "Project Path" edit
 * box.
 * Note that the chosen path will be the parent of the new project's
 * directory, created under it using the project's name.
 * @return	The full path of the parent directory for the new project
 */
/*
QString NewProjectDlg::getPath()
{
	if (m_pHiddenDirCheck->isChecked())
		return QString(m_pSrcRootRequester->url()) + "/.cscope";
	
	return m_pPathRequester->url();
}
*/

void NewProjectDlg::slotAddType()
{
	qDebug() << "NewProjectDlg::slotAddType stub\n";
}

/*
/home/follinge/projects/kscope-kde4/src/newprojectdlg4.cpp:137: error: prototype for 'void NewProjectDlg::slotAvailTypesChanged(QString&)' does not match any in class 'NewProjectDlg'
/home/follinge/projects/kscope-kde4/src/newprojectdlg4.h:60: error: candidate is: void NewProjectDlg::slotAvailTypesChanged(const QString&)
/
*/
void NewProjectDlg::slotAvailTypesChanged(const QString &qstr)
{
	qDebug() << "NewProjectDlg::slotAvailTypesChanged stub\n";
}

void NewProjectDlg::slotRemoveType()
{
	qDebug() << "NewProjectDlg::slotRemoveType stub\n";
}

void NewProjectDlg::accept()
{
	qDebug() << "NewProjectDlg::accept stub\n";
}

/**
 * Class constructor.
 * @param	pParent		The parent widget
 * @param	szName		The widget's name
 */
AutoCompletionDlg::AutoCompletionDlg(QWidget* pParent,
	const char* szName ) 
{
}

/**
 * Class destructor.
 */
AutoCompletionDlg::~AutoCompletionDlg()
{
}

// Mon Jun 20 19:44:33 UTC 2011
