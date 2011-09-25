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

// BEGIN AutoCompletionDlg
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

/**
 * Stores the values set by the user in the dialogue widgets, and terminates
 * the dialogue.
 * This slot is connected to the clicked() signal of the "OK" button.
 */
void AutoCompletionDlg::accept()
{
	// Store widget values
	m_nMinChars = m_pMinCharsSpin->value();
	m_nDelay = m_pDelaySpin->value();
	m_nMaxEntries = m_pMaxEntriesSpin->value();
	
	// Close the dialogue, indicating acceptance
	QDialog::accept();
}

/**
 * Displays the dialogue, and waits for either the "OK" or "Cancel" button to
 * be clicked.
 * Before the dialogue is displayed, the stored values are set to the widgets.
 * @return	The dialogue's termination code
 */
int AutoCompletionDlg::exec()
{
	// Set current values
	m_pMinCharsSpin->setValue(m_nMinChars);
	m_pDelaySpin->setValue(m_nDelay);
	m_pMaxEntriesSpin->setValue(m_nMaxEntries);

	// Show the dialogue
	return QDialog::exec();
}
// END AutoCompletionDlg

NewProjectDlg::NewProjectDlg(bool bNewProj, QWidget* pParent, 
	const char* szName) :
	Ui::NewProjectLayout(),
	m_bNewProj(bNewProj)
{
	// Must do this _before_ we connect signals and slots
	setupUi(this);

	// BEGIN OLD STUFF
	ProjectBase::Options opt;

	// FIXME:
	// Create the auto-completion sub-dialogue
	m_pAutoCompDlg = new AutoCompletionDlg(this);
	
	// Restrict the path requester to existing directories.
	m_pPathRequester->setMode(KFile::Directory | KFile::ExistingOnly | 
		KFile::LocalOnly);

	/*
	m_pSrcRootRequester->setMode(KFile::Directory | KFile::ExistingOnly | 
			KFile::LocalOnly);
	*/
	
	// Set up the Create/Cancel buttons	
	connect(m_pCreateButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(m_pCancelButton, SIGNAL(clicked()), this, SLOT(reject()));

	// Show the auto-completion properties dialogue
	connect(m_pACButton, SIGNAL(clicked()), m_pAutoCompDlg, SLOT(exec()));	
		
	// FIXME:
	// Perform actions specific to the type of dialog (new project or
	// project properties)
	if (bNewProj) {
		// Set default project properties
		ProjectBase::getDefOptions(opt);
		setProperties("", "", opt);
	}
	else {
		// Give appropriate titles to the dialog and the accept button
		setWindowTitle(i18n("Project Properties"));
		m_pCreateButton->setText(i18n("OK"));
		
		// Disable the non-relevant widgets
		m_pNameEdit->setEnabled(false);
		m_pPathRequester->setEnabled(false);
	}
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
QString NewProjectDlg::getName()
{
	qDebug() << "NewProjectDlg::getName\n";
	return m_pNameEdit->text();
}

/**
 * Retrieves the text entered by the user in the dialog's "Project Path" edit
 * box.
 * Note that the chosen path will be the parent of the new project's
 * directory, created under it using the project's name.
 * @return	The full path of the parent directory for the new project
 */
QString NewProjectDlg::getPath()
{
	qDebug() << "NewProjectDlg::getPath\n";
	if (m_pHiddenDirCheck->isChecked())
		return QString(m_pSrcRootRequester->text()) + "/.cscope";
	
	return m_pPathRequester->text();
}

void NewProjectDlg::slotAddType()
{
	qDebug() << "NewProjectDlg::slotAddType stub\n";
}

void NewProjectDlg::slotAvailTypesChanged(const QString &qstr)
{
	qDebug() << "NewProjectDlg::slotAvailTypesChanged stub\n";
}

void NewProjectDlg::slotRemoveType()
{
	qDebug() << "NewProjectDlg::slotRemoveType stub\n";
}

/**
 * Configures the dialog's widget to display the properties of the current
 * project.
 * @param	sName	The project's name
 * @param	sPath	The project's path
 * @param	opt		Project parameters configurable in this dialogue
 */
void NewProjectDlg::setProperties(const QString& sName, const QString& sPath,
	const ProjectBase::Options& opt)
{
	qDebug() << "NewProjectDlg::setProperties(): \n";
	QStringList::ConstIterator itr;
	
	// Set values for current project
	m_pNameEdit->setText(sName);
	m_pPathRequester->setText(sPath);
	m_pSrcRootRequester->setText(opt.sSrcRootPath);
	m_pKernelCheck->setChecked(opt.bKernel);
	m_pInvCheck->setChecked(opt.bInvIndex);
	m_pNoCompCheck->setChecked(opt.bNoCompress);
	m_pSlowPathCheck->setChecked(opt.bSlowPathDef);
	
	if (opt.nAutoRebuildTime >= 0) {
		m_pAutoRebuildCheck->setChecked(true);
		m_pAutoRebuildSpin->setValue(opt.nAutoRebuildTime);
	}

	if (opt.bACEnabled) {
		m_pACCheck->setChecked(true);
	}
	
	if (opt.nTabWidth > 0) {
		m_pTabWidthCheck->setChecked(true);
		m_pTabWidthSpin->setValue(opt.nTabWidth);
	}
	
	// Initialise the auto-completion sub-dialogue
	m_pAutoCompDlg->m_nMinChars = opt.nACMinChars;
	m_pAutoCompDlg->m_nDelay = opt.nACDelay;
	m_pAutoCompDlg->m_nMaxEntries = opt.nACMaxEntries;
	
	// Add type strings to the types list box
	for (itr = opt.slFileTypes.begin(); itr != opt.slFileTypes.end(); ++itr)
		m_pTypesList->insertItem(*itr);
	
	m_pCtagsCmdEdit->setText(opt.sCtagsCmd);
}

/**
 * Ends the dialog after the user has clicked the "OK" button.
 */
void NewProjectDlg::accept()
{
	int i, nCount;

	qDebug() << "NewProjectDlg::accept() BEGIN\n";
	
	// Validate the name of a new project
	if (m_bNewProj) {
		QRegExp re("[^ \\t\\n]+");
		if (!re.exactMatch(m_pNameEdit->text())) {
			KMessageBox::error(0, i18n("Project names must not contain "
				"whitespace."));
			return;
		}
	}
	
	// Fill the string list with all file types
	nCount = (int)m_pTypesList->count();
	for (i = 0; i < nCount; i++)
		m_slTypes.append(m_pTypesList->text(i));

	// Clean-up the source root
	QDir dir(m_pSrcRootRequester->text());
	if (dir.exists())
		m_pSrcRootRequester->setText(dir.absolutePath());
	else
		m_pSrcRootRequester->setText("/");
		
	// Close the dialog
	QDialog::accept();
}

// Mon Jun 20 19:44:33 UTC 2011
