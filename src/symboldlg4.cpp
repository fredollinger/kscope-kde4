#include <qlabel.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qcheckbox.h>
#include <qgroupbox.h>
#include <kcombobox.h>
#include <klocale.h>

#include "symboldlg4.h"
#include "cscopefrontend4.h"
#include "kscopeconfig4.h"

QStringList SymbolDlg::s_slHistory;

/**
 * Class constructor.
 * @param	pParent	Parent widget
 * @param	szName	This widget's name
 */
SymbolDlg::SymbolDlg(QWidget* pParent, const char* szName) : 
	//Ui::SymbolLayout(pParent, szName, true, 0),
	Ui::SymbolLayout() 
{
	/*
	// Create a persistent Cscope process
	m_pCscope = new CscopeFrontend();
	
	// Initialise the hint list (hidden by default)
	m_pHintList->addColumn(i18n("Suggested Symbols"));
	m_pHintList->hide();
	((QWidget*)m_pHintGroup)->hide();
	m_pBeginWithRadio->toggle();
	adjustSize();
	
	// Close the dialogue when either the "OK" or "Cancel" button are clicked
	connect(m_pOKButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(m_pCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	
	// Run a symbol completion query when the "Hint" button is clicked
	connect(m_pHintButton, SIGNAL(clicked()), this, SLOT(slotHintClicked()));
	
	// Add results to the hint list
	connect(m_pCscope, SIGNAL(dataReady(FrontendToken*)), this,
		SLOT(slotHintDataReady(FrontendToken*)));

	// Set hint button availability based on the type of query
	connect(m_pTypeCombo, SIGNAL(activated(int)), this, 
		SLOT(slotTypeChanged(int)));
		
	// Selecting an item in the hint list sets it as the current text	
	connect(m_pHintList, SIGNAL(selectionChanged(QListViewItem*)), this,
		SLOT(slotHintItemSelected(QListViewItem*)));
	
	// Double-clicking an item in the hint list accepts that item as the
	// result of the query (i.e., the item is selcted and the dialogue is
	// closed)
	connect(m_pHintList, SIGNAL(doubleClicked(QListViewItem*)), this,
		SLOT(accept()));
		
	// Refresh the hint list when the hint options change
	connect(m_pBeginWithRadio, SIGNAL(toggled(bool)), this,
		SLOT(slotHintOptionChanged(bool)));
	connect(m_pContainRadio, SIGNAL(toggled(bool)), this,
		SLOT(slotHintOptionChanged(bool)));
		
	// Show hint query progress information
	connect(m_pCscope, SIGNAL(progress(int, int)), this,
		SLOT(slotHintProgress(int, int)));
	connect(m_pCscope, SIGNAL(finished(uint)), this,
		SLOT(slotHintFinished(uint)));
	*/
}

/**
 * Class destructor.
 */
SymbolDlg::~SymbolDlg()
{
	delete m_pCscope;
}

// #include "symboldlg.moc"
// Sun Aug 28 13:58:53 PDT 2011