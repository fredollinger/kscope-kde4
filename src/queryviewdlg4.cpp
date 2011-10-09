#include "queryviewdlg4.h"
#include "queryviewdriver4.h"

/**
 * Class constructor.
 * @param	nFlags	Controls the behaviour of the diaogue
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
QueryViewDlg::QueryViewDlg(uint nFlags, QWidget* pParent, 
	const char* szName) :
	QueryViewLayout(pParent, szName),
	m_nFlags(nFlags)
{
	// Set the destructive flag, if required
	if (nFlags & DestroyOnClose)
		setWFlags(getWFlags() | WDestructiveClose);
		
	// Create a driver for running queries
	m_pDriver = new QueryViewDriver(m_pView, this);
		
	// Show the dialogue when instructed by the driver
	connect(m_pView, SIGNAL(needToShow()), this, SLOT(slotShow()));	
	
	// Propagate the lineRequested() signal from the QueryView object
	connect(m_pView, SIGNAL(lineRequested(const QString&, uint)), this,
		SLOT(slotLineRequested(const QString&, uint)));
		
	// Make the dialogue modal
	setModal(true);
}

/**
 * Class destructor.
 */
QueryViewDlg::~QueryViewDlg()
{
}

/**
 * Starts a query.
 * @param	nType	The type of the query
 * @param	sText	The query's text
 * @param	bCase		true for case-sensitive queries, false otherwise
 */
void QueryViewDlg::query(uint nType, const QString& sText, bool bCase)
{
	m_pDriver->query(nType, sText, bCase);
}

/**
 * Make the dialogue visible when instructed by the driver.
 * This slot is connected to the show() signal emitted by the QueryViewDriver
 * object.
 */
void QueryViewDlg::slotShow()
{
	show();
}

/**
 * Propagates the lineRequested() signal from the view object.
 * If the CloseOnSelect flag is set, the dialogue is closed.
 * This slot is connected to the lineRequested() signal emitted by the
 * QueryView widget.
 */
void QueryViewDlg::slotLineRequested(const QString& sFileName, uint nLine)
{
	emit lineRequested(sFileName, nLine);
	
	if (m_nFlags & CloseOnSelect)
		close();
}

/**
 * @return	A QueryView iterator initialised to the beginning of the result
 *			list
 */
QueryView::Iterator QueryViewDlg::getIterator()
{
	return m_pView->getIterator();
}

#include "queryviewdlg.moc"
