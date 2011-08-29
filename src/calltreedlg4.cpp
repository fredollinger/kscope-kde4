#include <qfile.h>
#include <qtoolbutton.h>
#include <qbuttongroup.h>
#include <klocale.h>
#include <kfiledialog.h>
#include "calltreedlg4.h"
#include "calltreelayout4.h"
#include "kscopepixmaps4.h"
#include "kscopeconfig4.h"

/** The currently supported version of saved call-tree files. */
#define FILE_VERSION		5

/** Window flags for call-tree widgets. */
#define CALL_TREE_W_FLAGS \
	WStyle_Customize | \
	WStyle_NormalBorder | \
	WStyle_Title | \
	WDestructiveClose

/** File Name index for the file name generation */
int CallTreeDlg::s_nFileNameIndex = 0;

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
CallTreeDlg::CallTreeDlg(QWidget* pParent, const char* szName) :
	CallTreeLayout()
{
	/*
	// Set button pixmaps
	// m_pCalledButton->setPixmap(GET_PIXMAP(CalledTree));
	// m_pCallingButton->setPixmap(GET_PIXMAP(CallingTree));
	// m_pGraphButton->setPixmap(GET_PIXMAP(CallGraph));
	m_pSaveButton->setPixmap(GET_PIXMAP(ButtonSaveAs));
	m_pZoomInButton->setPixmap(GET_PIXMAP(ButtonZoomIn));
	m_pZoomOutButton->setPixmap(GET_PIXMAP(ButtonZoomOut));
	m_pRotateButton->setPixmap(GET_PIXMAP(ButtonRotate));
	m_pPrefButton->setPixmap(GET_PIXMAP(ButtonPref));
	*/
	
	// Open the location of a call
	/*
	// connect(m_pGraphWidget, SIGNAL(lineRequested(const QString&, uint)),
		// this, SIGNAL(lineRequested(const QString&, uint)));
	connect(m_pCalledWidget, SIGNAL(lineRequested(const QString&, uint)),
		this, SIGNAL(lineRequested(const QString&, uint)));
	connect(m_pCallingWidget, SIGNAL(lineRequested(const QString&, uint)),
		this, SIGNAL(lineRequested(const QString&, uint)));
	*/
	
	// m_pCallingWidget->setMode(TreeWidget::Calling);
	
	// Get the default view from KScope's configuration
	m_nDefView = Config().getDefGraphView();
}

/**
 * Class destructor.
 */
CallTreeDlg::~CallTreeDlg()
{
}

/**
 * @param	sFunc	The function to use as the root of the call tree
 */
void CallTreeDlg::setRoot(const QString& sFunc)
{
	m_sRoot = sFunc;
	
	// Generate unique file name to save call tree later
	m_sFileName = sFunc;
	m_sFileName.replace(' ', '_');
	m_sFileName += QString::number(++s_nFileNameIndex);
	
	// Set the root item in all views
	/*
	// m_pGraphWidget->setRoot(sFunc);
	m_pCalledWidget->setRoot(sFunc);
	m_pCallingWidget->setRoot(sFunc);
	*/
}

/**
 * Displays the dialogue.
 */
/*
void CallTreeDlg::show()
{
	// Set the default view.
	m_pViewGroup->setButton(m_nDefView);
	m_pStack->raiseWidget(m_nDefView);
	slotViewChanged(m_nDefView);
	
	// CallTreeLayout::show();
}
*/

/**
 * Informs the call tree manager that this object should be removed from the
 * list of call tree dialogues.
 * The close event is received when the dialogue is explicitly closed by the
 * user. This dialogue will not appear when the project is reopened, and it
 * is therefore safe to delete the graph file at this point.
 * @param	pEvent	Information on the closing event 
 */
void CallTreeDlg::closeEvent(QCloseEvent* pEvent)
{
	if (!m_sFilePath.isEmpty())
		QFile::remove(m_sFilePath);
		
	emit closed(this);
	QWidget::closeEvent(pEvent);
}

// extern void yyinit(CallTreeDlg*, FILE*, Encoder*);
extern int yyparse();

/**
 * Restores a call tree from the given call tree file.
 * NOTE: The call tree file is deleted when loading is complete.
 * @param	sProjPath	The full path of the project directory
 * @param	sFileName	The name of the call tree file to load
 * @return	true if successful, false otherwise
 */
bool CallTreeDlg::load(const QString& sProjPath, const QString& sFileName)
{
	/*
	QString sPath;
	FILE* pFile;
	int nVersion, nView, nResult;
	const QChar *qc;
	// Encoder enc;
	
	// Create the full path name
	sPath = sProjPath + "/" + sFileName;
	
	// Open the file for reading
	qc=sPath.unicode();
	pFile = fopen(qc->toLatin1(), "r");
	if (pFile == NULL)
		return false;
		
	// Check file version
	if ((fscanf(pFile, "VERSION=%d\n", &nVersion) != 1) || 
		(nVersion != FILE_VERSION)) {
		fclose(pFile);
		return false;
	}
		
	// Get default view
	if ((fscanf(pFile, "View=%d\n", &nView) == 1) &&
		(nView >= 0) &&
		(nView <= 2)) {
		m_nDefView = nView;
	}
	
	// Read the call trees and the graph stored on this file
	yyinit(this, pFile, &enc);
	nResult = yyparse();
		 
	// Close the file
	fclose(pFile);
	
	// Check the result returned by the parser
	if (nResult != 0)
		return false;
	
	// Store the file name
	m_sFileName = sFileName;
	m_sFilePath = sPath;
	
	// Draw the graph
	m_pGraphWidget->draw();
	*/

	return true;
}

// #include "calltreedlg.moc"
