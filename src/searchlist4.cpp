#include "searchlist4.h"

/**
 * Intercepting additional key events of QLineEdit to browse the list
 * @param	pKey	The pressed key event
 */
void SearchLineEdit::keyPressEvent(QKeyEvent* pKey) 
{
	/*
	switch(pKey->key()) {
	case Qt::Key_Up:
	case Qt::Key_Down:
	case Qt::Key_PageUp:
	case Qt::Key_PageDown:
		emit keyPressed(pKey); 
		break;
	
	default:
		QLineEdit::keyPressEvent(pKey);
		break;
	}
	*/
}

/**
 * Class constructor.
 * @param	nSearchCol	The list column on which to perform string look-ups
 * @param	pParent		The parent widget
 * @param	szName		The widget's name
 */
SearchList::SearchList(int nSearchCol, QWidget* pParent, const char* szName) :
	QWidget(pParent),
	m_nSearchCol(nSearchCol)
{
	// Create the child widgets
	m_pEdit = new SearchLineEdit(this);
	m_pList = new QListView(this);
	
	// Set up the tooltip generator
	// QToolTip::remove(m_pList);
	// m_pToolTip = new ListToolTip(this);
	
	connect(m_pEdit, SIGNAL(textChanged(const QString&)), this,
		SLOT(slotFindItem(const QString&)));
	connect(m_pList, SIGNAL(doubleClicked(QListWidgetItem*)), this,
		SLOT(slotItemSelected(QListWidgetItem*)));
	connect(m_pList, SIGNAL(returnPressed(QListWidgetItem*)), this,
		SLOT(slotItemSelected(QListWidgetItem*)));
	connect(m_pEdit, SIGNAL(returnPressed()), this,
		SLOT(slotItemSelected()));
	connect(m_pEdit, SIGNAL(keyPressed(QKeyEvent*)), this,
		SLOT(slotKeyPressed(QKeyEvent*)));
}

/**
 * Class destructor.
 */
SearchList::~SearchList()
{
	// delete m_pToolTip;
}

/**
 * Sets the keyboad focus to the search box.
 */
void SearchList::slotSetFocus()
{
	m_pEdit->setFocus();
}

/**
 * Selects a list item whose string begins with the text entered in the edit
 * widget.
 * This slot is connected to the textChanged() signal of the line edit widget.
 * @param	sText	The new text in the edit widget
 */
void SearchList::slotFindItem(const QString& sText)
{
	QListWidgetItem* pItem;
	
	// Try to find an item that contains this text
	// Priority to exactly matched, 
	// then try to find line begins with the text,
	// and if not found, then try to find the line contains the text
	/*
	pItem = m_pList->findItem(sText, m_nSearchCol, 
		ExactMatch | BeginsWith | Contains);
	*/

	// Select this item
	/*
	if (pItem != 0) {
		m_pList->setSelected(pItem, true);
		m_pList->ensureItemVisible(pItem);
	}
	*/
}

/**
 * Lets inheriting classes process an item selection made through the list 
 * widget.
 * This slot is connected to the doubleClicked() and returnPressed()
 * signals of the list widget.
 */
void SearchList::slotItemSelected(QListWidgetItem* pItem)
{
	// processItemSelected(pItem);
	m_pEdit->setText("");
}

/**
 * Lets inheriting classes process an item selection made through the edit 
 * widget.
 * This slot is connected to the returnPressed() signal of the edit widget.
 */
void SearchList::slotItemSelected()
{
	QListWidgetItem* pItem;

	/*
	if ((pItem = m_pList->selectedItem()) != NULL) {
		m_pEdit->setText(pItem->text(m_nSearchCol));
		// processItemSelected(pItem);
	}
	*/
	
// 	m_pEdit->setText("");
}

#define SEARCH_MATCH(pItem) \
	pItem->text(m_nSearchCol).startsWith(m_pEdit->text())

/**
 * Sets a new current item based on key events in the edit box.
 * This slot is connected to the keyPressed() signal of the edit widget.
 * @param	pKey	The key evant passed by the edit box
 */
void SearchList::slotKeyPressed(QKeyEvent* pKey)
{
	/*
	QListWidgetItem* pItem, * pNewItem;
	int nPageSize, nPos;

	// Select the current item, or the first one if there is no current item
	pItem = m_pList->currentItem();
		
	// Set a new current item based on the pressed key
	switch (pKey->key()) {
	case  Qt::Key_Up:
		if (pItem) {
			for (pNewItem = pItem->itemAbove(); 
				pNewItem && !SEARCH_MATCH(pNewItem);
				pNewItem = pNewItem->itemAbove());
				
			if (pNewItem)
				pItem = pNewItem;
		}
		break;
		
	case  Qt::Key_Down:
		if (pItem) {
			for (pNewItem = pItem->itemBelow(); 
				pNewItem && !SEARCH_MATCH(pNewItem);
				pNewItem = pNewItem->itemBelow());
				
			if (pNewItem)
				pItem = pNewItem;
		}
		break;
	
	case  Qt::Key_PageUp:
		nPageSize = m_pList->visibleHeight() / pItem->height();
		for (nPos = 0; 
			pItem && pItem->itemAbove() && (nPos < nPageSize); 
			nPos++)
			pItem = pItem->itemAbove();
		break;
		
	case  Qt::Key_PageDown:
		nPageSize = m_pList->visibleHeight() / pItem->height();
		for (nPos = 0; 
			pItem && pItem->itemBelow() && (nPos < nPageSize); 
			nPos++)
			pItem = pItem->itemBelow();
		break;
	
	default:
		pKey->ignore();
		return;
	}

	// Select the first item if no other item was selected
	if (pItem == NULL)
		pItem = m_pList->firstChild();
		
	// Select the new item
	if (pItem) {
		m_pList->setSelected(pItem, true);
		m_pList->ensureItemVisible(pItem);
	}
	*/
}

// #include "searchlist.moc"
