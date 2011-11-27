#include <klocale.h>
#include "historypage4.h"
#include "historyview4.h"

namespace kscope4{
int HistoryPage::s_nMaxPageID = 0;

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
HistoryPage::HistoryPage(QWidget* pParent, const char* szName) :
	QueryPageBase(pParent, szName),
	m_nPageID(++s_nMaxPageID)
{
	m_pView = new HistoryView(this);
	
	connect(m_pView, SIGNAL(lineRequested(const QString&, uint)), this,
		SIGNAL(lineRequested(const QString&, uint)));
	
	// Set colours and font
	applyPrefs();
}

/**
 * Class destructor.
 */
HistoryPage::~HistoryPage()
{
	if (s_nMaxPageID == m_nPageID)
		s_nMaxPageID--;
}

/**
 * Creates a new position history record at the top of the list.
 * @param	sFile	The file name associated with the record
 * @param	nLine	The line number
 * @param	sText	The text of the file at the given line
 */
void HistoryPage::addRecord(const QString& sFile, uint nLine, 
	const QString& sText)
{
	HistoryItem* pItem, * pNextItem;
	
	pItem = (HistoryItem*)m_pView->currentItem();
	if (pItem != NULL) {
		// Do not add duplicate items
		if ((pItem->text(1) == sFile) && (pItem->text(2).toUInt() == nLine))
			return;
			
		// Remove all items above the current one, so the new item is added to
		// the top of the list
		pItem = pItem->m_pPrevSibling;
		while (pItem != NULL) {
			pNextItem = pItem;
			pItem = pItem->m_pPrevSibling;
			delete pNextItem;
		}
	}
	
	// Create the new item at the top of the list
	m_pView->addRecord("", sFile, QString::number(nLine), sText, NULL);
}

/**
 * Creates a new history item.
 * This version is used when history records are read from a file.
 * @param	sFile	The file name
 * @param	sLine	The line number
 * @param	sText	The contents of the line
 */
void HistoryPage::addRecord(const QString&, const QString& sFile,
	const QString& sLine, const QString& sText)
{
	m_pView->addRecord("", sFile, sLine, sText, NULL);
}

/**
 * Creates a tab caption for this page, based on the unique page ID.
 * @param	bBrief	true to use brief caption names, false otherwise
 */
QString HistoryPage::getCaption(bool bBrief) const
{
	return (bBrief ? QString(i18n("HIS ")) : QString(i18n("History "))) +
		QString::number(m_nPageID);
}

/**
 * Creates a unique file name for saving the contents of the history page.
 * @return	The unique file name to use
 */
QString HistoryPage::getFileName(const QString&) const
{
	return QString("History_") + QString::number(m_nPageID);
}
} // namespace kscope4
// Fri Nov 25 19:40:20 PST 2011
