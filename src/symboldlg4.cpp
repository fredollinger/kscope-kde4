#include <QListWidgetItem>
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

namespace kscope4{
QStringList SymbolDlg::s_slHistory;

/**
 * Class constructor.
 * @param	pParent	Parent widget
 * @param	szName	This widget's name
 */
SymbolDlg::SymbolDlg(QWidget* pParent, const char* szName) : 
	Ui::SymbolLayout(),
	m_progress(m_pHintList)
{
	qDebug() << "SymbolDlg::SymbolDlg(): calling CscopeFrontend()";
	// Create a persistent Cscope process
	m_pCscope = new CscopeFrontend();
	
	#if 0
	// Initialise the hint list (hidden by default)
	
	// FIXME: We set model, there is no notion addColumn()
	// m_pHintList->addColumn(i18n("Suggested Symbols"));

	// qDebug() << "SymbolDlg::SymbolDlg(): m_pHintList->hide()";
	// m_pHintList->hide();
	// qDebug() << "SymbolDlg::SymbolDlg(): pHintGroup->hide()";
	// ((QWidget*)m_pHintGroup)->hide();
	qDebug() << "SymbolDlg::SymbolDlg(): toggle()";
	m_pBeginWithRadio->toggle();
	qDebug() << "SymbolDlg::SymbolDlg(): adjustSize()";
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
	#endif
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
	qDebug() << "SymbolDlg::setType()";
	// m_pTypeCombo->setCurrentIndex(nType);
	qDebug() << "SymbolDlg::setType() calling: slotTypeChanged()";
	slotTypeChanged(nType);
}

/**
 * @param	sSymbol	The initial text of the combo-box
 */
void SymbolDlg::setSymbol(const QString& sSymbol)
{
	qDebug() << "SymbolDlg::setSymbol(): FIXME: NOT IMPLEMENTED";
	// m_pSymbolHC->setItemText(0, sSymbol);
}

/**
 * @param	slSymHistory	A list of previously queried symbols
 */
void SymbolDlg::setHistory(QStringList& slSymHistory)
{
	qDebug() << "SymbolDlg::setHistory(): FIXME: NOT IMPLEMENTED";
	// m_pSymbolHC->setHistoryItems(slSymHistory);
}

/**
 * @return	The current text of the symbol combo-box
 */
QString SymbolDlg::getSymbol() const
{
	QString sResult;
	
	sResult = m_pSymbolHC->currentText().trimmed();
	#if 0
	if (m_pSubStringCheck->isChecked())
		sResult = ".*" + sResult + ".*";
	#endif
		
	return sResult;
}

/**
 * @return	The type of query requested by the user
 * @note	The returned value does not conform to the type used for running
 * 			Cscope queries. Use getQueryType() to translate between these
 *			values.
 */
uint SymbolDlg::getType() const
{
	return m_pTypeCombo->currentIndex();
}

bool SymbolDlg::getCase() const
{
	// return !m_pCaseCheck->isChecked();
	return true;
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
	qDebug() << "SymbolDlg::promptSymbol()";
	SymbolDlg dlg(pParent);
	SymbolDlg *widget = new SymbolDlg();
	dlg.setupUi(widget);
	
	// Initialise the dialogue
	qDebug() << "SymbolDlg::promptSymbol() calling setType()";
	dlg.setType(nType);
	qDebug() << "SymbolDlg::setHistory()";
	dlg.setHistory(s_slHistory);
	qDebug() << "SymbolDlg::setSymbol()";
	dlg.setSymbol(sSymbol);
	
	// Display the dialogue
	qDebug() << "SymbolDlg::exec()";
	widget->exec();
	#if 0
	if (dlg.exec() != QDialog::Accepted)
		return "";
	#endif
	
	// Return the text entered by the user
	nType = dlg.getType();
	bCase = dlg.getCase();
	qDebug() << "SymbolDlg::addToHistory()";
	dlg.m_pSymbolHC->addToHistory(dlg.getSymbol());
	s_slHistory = dlg.m_pSymbolHC->historyItems();
	return dlg.getSymbol();
}

/**
 * Translates a symbol dialogue type into a Cscope query type.
 * @param	nType	The type to translate
 * @return	A query type matching the symbol dialogue type
 */
uint SymbolDlg::getQueryType(uint nType)
{
	if (nType == CallTree)
		return CscopeFrontend::None;
		
	if (nType <= Text)
		return nType;
		
	return nType + 1;
}

/**
 * Runs a symbol definition query, looking for symbols starting with the
 * currently entered text.
 * If the hint list is not visible, it is shown first.
 * This slot is connected to the clicked() signal of the "Hint" button.
 */
void SymbolDlg::slotHintClicked()
{
	QString sText, sRegExp;
	
	// Show the hint list if necessary
	if (!m_pHintList->isVisible()) {
		m_pHintList->show();
		// ((QWidget*)m_pHintGroup)->show();
		adjustSize();
	}
	
	// Clear the previous contents
	m_pHintList->clearSpans();
	
	// Get the currently entered text (must have at least one character)
	sText = m_pSymbolHC->currentText().trimmed();
	if (sText.isEmpty())
		return;

	// Create the regular expression
	#if 0
	if (m_pBeginWithRadio->isChecked())
		sRegExp = sText + "[a-zA-Z0-9_]*";
	else	
	#endif
	sRegExp = "[a-zA-Z0-9_]*" + sText + "[a-zA-Z0-9_]*";
	
	m_reHint.setPattern(sRegExp);

	// Run a Cscope symbol definition query using a regular expression
	m_pCscope->query(CscopeFrontend::Definition, sRegExp);
}

/**
 * Called when a new record is ready to be added to the hint list.
 * NOTE: Cscope 15.5 has a bug where the "function" field of the record
 * displays the regular expression instead of the matched symbol name. For
 * this reason, we need to extract the symbol from the "Text" field.
 * @param	pToken	The head of the record's token list
 */
void SymbolDlg::slotHintDataReady(FrontendToken* pToken)
{
	QString sText;

	QList<QTableWidgetItem *> ql;

	// Get the line text
	pToken = pToken->getNext()->getNext()->getNext();
	sText = pToken->getData();

	// Find the symbol within the line
	if (m_reHint.indexIn(sText) == -1)
		return;
	
	// Find the symbol within the list, if found - do not add
	ql = m_pHintList->findItems(m_reHint.capturedTexts().first(), 0);
	if (ql.size() > 0) return;
	/*
	if (NULL != (m_pHintList->findItems(m_reHint.capturedTexts().first(), 0)))
		return;
	*/
	
	// Add a list item
	// (void)new QListViewItem(m_pHintList, m_reHint.capturedTexts().first());
	QTableWidgetItem *newitem = new QTableWidgetItem(m_reHint.capturedTexts().first());
	m_pHintList->setItem(0, m_pHintList->columnCount()+1, newitem);

}

/**
 * Sets the text of a selected hint list item as the current text of the
 * symbol combo-box. 
 * This slot is connected to the doubleClicked() signal of the hint list-view.
 * @param	pItem	The clicked list item
 */
#if 0
void SymbolDlg::slotHintItemSelected(QTableWidgetItem* pItem)
{
	m_pSymbolHC->setItemText(0, pItem->data(0).toString());
	return;
}
#endif

/**
 * Refreshes the hint list based on the newly selected option.
 * This slot is connected to the toggled() signal of the hint options radio
 * buttons.
 * NOTE: The list is only refreshed if the system profile is set to Fast.
 * @param	bOn	true if the button was toggled on
 */
void SymbolDlg::slotHintOptionChanged(bool bOn)
{
	if (bOn && Config().getSysProfile() == KScopeConfig::Fast)
		slotHintClicked();
}

/**
 * Display a progress bar while the hint query is working.
 * This slot is connected to the progress() signal emitted by the Cscope
 * frontend object.
 * @param	nProgress	Progress value
 * @param	nTotal		The final expected value
 */
void SymbolDlg::slotHintProgress(int nProgress, int nTotal)
{
	m_progress.setProgress(nProgress, nTotal);
}

/**
 * Destroys all progress information widget when the query process terminates.
 * This slot is connected to the finished() signal emitted by the Cscope
 * process.
 */
void SymbolDlg::slotHintFinished(uint /* ignored */)
{
	m_progress.finished();
}

/**
 * Enables/disables the hint button, based on the newly selected type.
 * This slot is connected to the activated() signal of the type combo-box.
 * @param	nType	The newly selected type
 */
void SymbolDlg::slotTypeChanged(int nType)
{
	qDebug() << "SymbolDlg::slotTypeChanged()";
	if (nType == FileName || nType == Including){
		qDebug() << "SymbolDlg::m_pHintButton->setEnabled(false)";
		// m_pHintButton->setEnabled(false);
	}
	else{
		// qDebug() << "SymbolDlg::m_pHintButton->setEnabled(true)";
		// m_pHintButton->setEnabled(true);
	}
}
} // namespace kscope4
// Sat Jan 14 20:13:39 PST 2012
