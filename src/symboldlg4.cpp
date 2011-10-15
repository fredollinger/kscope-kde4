#include <qlabel.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qcheckbox.h>
#include <qgroupbox.h>
#include <kcombobox.h>
#include <klocale.h>

#include "cscopefrontend4.h"
#include "kscopeconfig4.h"
#include "symboldlg4.h"
#include "symbollayout4.h"

#include "qdebug.h"

QStringList SymbolDlg::s_slHistory;

/**
 * Class constructor.
 * @param	pParent	Parent widget
 * @param	szName	This widget's name
 */
SymbolDlg::SymbolDlg(QWidget* pParent, const char* szName) : 
	 Ui::SymbolLayout() 
{
	qDebug() << "SymbolDlg() constructor \n";
	// Create a persistent Cscope process
	m_pCscope = new CscopeFrontend();

	// Must do this _before_ we connect signals and slots
	setupUi(this);
	/*

	
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

/**
 * Displays the requested type of query in the type combo-box.
 * @param	nType	The requested type
 */
void SymbolDlg::setType(uint nType)
{
	// m_pTypeCombo->setCurrentIndex(nType);
	slotTypeChanged(nType);
}


/**
 * A convinience static function for creating and showing SymbolDlg dialogue.
 * @param	pParent		The parent widget
 * @param	nType		The type of query requested by the user (may be
 *						changed in the dialogue)
 * @param	sSymbol		The initial text of the combo-box
 * @return	The text entered by the user in the symbol combo-box, or an empty
 *			string if the dialogue was cancelled
 */
QString SymbolDlg::promptSymbol(QWidget* pParent, uint& nType, 
	const QString& sSymbol, bool& bCase)
{

	qDebug() << "symboldld.c: promptSymbol NOT DONE \n";
	SymbolDlg dlg(pParent);

	// Initialise the dialogue
	dlg.setType(nType);

	/*
	dlg.setHistory(s_slHistory);
	*/
	dlg.setSymbol(sSymbol);
	
	dlg.show();
	// Display the dialogue
	if (dlg.exec() != QDialog::Accepted)
		return "";
	
	/*
	// Return the text entered by the user
	nType = dlg.getType();
	bCase = dlg.getCase();
	dlg.m_pSymbolHC->addToHistory(dlg.getSymbol());
	s_slHistory = dlg.m_pSymbolHC->historyItems();
	*/
	return dlg.getSymbol();
}

/**
 * @return	The current text of the symbol combo-box
 */
QString SymbolDlg::getSymbol() const
{
	QString sResult;
	
	qDebug() << "symboldld.c: getSymbol NOT DONE \n";
	/*
	sResult = m_pSymbolHC->currentText().stripWhiteSpace();
	if (m_pSubStringCheck->isChecked())
		sResult = ".*" + sResult + ".*";
	*/
		
	return sResult;
}

/**
 * Translates a symbol dialogue type into a Cscope query type.
 * @param	nType	The type to translate
 * @return	A query type matching the symbol dialogue type
 */
uint SymbolDlg::getQueryType(uint nType)
{
//	if (nType == CallTree)
//		return CscopeFrontend::None;
		
	if (nType <= Text)
		return nType;
		
	return nType + 1;
}

/**
 * Enables/disables the hint button, based on the newly selected type.
 * This slot is connected to the activated() signal of the type combo-box.
 * @param	nType	The newly selected type
 */
void SymbolDlg::slotTypeChanged(int nType)
{
	#if 0
	if (nType == FileName || nType == Including)
		// m_pHintButton->setEnabled(false);
	else
		// m_pHintButton->setEnabled(true);
	#endif
}

/**
 * @param	sSymbol	The initial text of the combo-box
 */
void SymbolDlg::setSymbol(const QString& sSymbol)
{
	// m_pSymbolHC->setCurrentText(sSymbol);
}

/**
 * @param	slSymHistory	A list of previously queried symbols
 */
void SymbolDlg::setHistory(QStringList& slSymHistory)
{
	// m_pSymbolHC->setHistoryItems(slSymHistory);
}

// Sat Oct 15 14:49:45 PDT 2011

