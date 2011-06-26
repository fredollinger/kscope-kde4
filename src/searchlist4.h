#ifndef SEARCHLIST_H
#define SEARCHLIST_H

#include <qwidget.h>
#include <qlineedit.h>
#include <qlistview.h>
#include <QListWidgetItem>
// #include "listviewitem4.h"

class SearchList;

/**
 * Defines a line text edit for searchable list view.
 * The widget is based on QLineEdit with additional key functions
 * Supported key events (up and down) are emitted as signals
 * @author Albert Yosher
 */
class SearchLineEdit : public QLineEdit
{
   Q_OBJECT
public:
	SearchLineEdit(QWidget* pParent) : QLineEdit(pParent) {};
	~SearchLineEdit() {};
	
signals:
	/**
	 * Emitted when one of the up/down or page up/page down keys were pressed
	 * inside this edit widget.
	 * @param	pEvent	The event received for this key press
	 */
	void keyPressed(QKeyEvent* pEvent);
	
private:
	virtual void keyPressEvent(QKeyEvent*);
};


/**
 * Defines a searchable list view.
 * The widget is composed of a list view, and an edit box used to enter
 * search data. Whenever the text in the edit box changes, the list view is
 * set to point to the first item that matches the new text.
 * @author Elad Lahav
 */
class SearchList : public QWidget
{
   Q_OBJECT

public: 
	SearchList(int nSearchCol, QWidget* pParent = 0, const char* szName = 0);
	~SearchList();

	/**
	 * @return	A pointer to the list part of the widget.
	 */
	QListView* getList() { return m_pList; }
	
	/**
	 * Constructs a tool-tip for the given item.
	 * @param	pItem	The item for which a tip is required
	 * @param	sTip	The constructed tip string (on return)
	 * @return	True to display the tip, false otherwise
	 */
	// virtual bool getTip(QListViewItem* pItem, QString& sTip) = 0;

public slots:
	void slotSetFocus();

protected:
	/** The search edit-box. */
	QLineEdit* m_pEdit;
	
	/** The list part of the widget. */
	QListView* m_pList;

	/**
	 * Called whenever the user selects an item in the list by either double-
	 * clicking it, or by highlighting the item and pressing the ENTER key.
	 * @param	pItem	The selected list item
	 */
	// virtual void processItemSelected(QListWidgetItem* pItem) = 0;
	
protected slots:
	void slotFindItem(const QString&);
	void slotItemSelected(QListWidgetItem*);
	void slotItemSelected();
	void slotKeyPressed(QKeyEvent*);
	
private:
	/** Specifies the search column, i.e., the list column whose strings are
		compared with the text in the search edit-box. */
	int m_nSearchCol;
	
	/** A tool-tip for the list entries. */
	// ListToolTip* m_pToolTip;
};

#endif
