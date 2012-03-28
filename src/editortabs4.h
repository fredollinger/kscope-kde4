#ifndef EDITORTABS_H
#define EDITORTABS_H

#include <qwidget.h>
#include "tabwidget4.h"
#include "editorpage4.h"
#include "projectmanager4.h"

class QueryView;

namespace kscope4{

typedef QMap<QString, EditorPage*> EditorMap;

/**
 * A tab widget that holds several editor windows.
 * This class provides the main widget in the KScope window. All editors are
 * opened as pages of the tab widgets.
 * @author Elad Lahav
 */

class EditorTabs : public TabWidget
{
   Q_OBJECT
   
public:
	EditorTabs(QWidget* pParent = 0, const char* szName = 0);
	~EditorTabs();

	EditorPage* findEditorPage(const QString&, bool bForceChange = false);
	EditorPage* getCurrentPage();

	void addEditorPage(EditorPage*);
	void applyPrefs();
	void getOpenFiles(FileListLocation&);
	bool removeAllPages();
	void removeCurrentPage();
	bool removePage(QWidget*, bool);
	void showBookmarks(QueryView*);
	
public slots:
	void slotSaveAll();
/*
	void slotRemovePage(QWidget*);
	void slotToggleTagList();
	void slotGoLeft();
	void slotGoRight();
*/
	
signals:
	/**
	 * Emitted when the current editor page changes.
	 * @param	pOld	The previous current page
	 * @param	pNew	The new current page
	 */
	void editorChanged(EditorPage* pOld, EditorPage* pNew);
	
	/**
	 * Emitted when an editor page is closed.
	 * @param	pPage	The removed page
	 */
	void editorRemoved(EditorPage* pPage);
	
	/**
	 * Indicates that files were dragged and dropped over the tab widget.
	 * @param	pEvent	The drop event information
	 */
	void filesDropped(QDropEvent* pEvent);
	
protected:
	virtual void dragMoveEvent(QDragMoveEvent*);
	virtual void dropEvent(QDropEvent*);
	
private:
	/** Links a file name with an editor page that has this file open. */
	EditorMap m_mapEdit;

	/** We need to keep track of the current page in order to implement the
		editorChanged() signal. */
	EditorPage* m_pCurPage;
	
	/** A popup menu with Cscope operations for the editor windows. */
	// QPopupMenu* m_pWindowMenu;
	
	/** The number of items added to the window menu (used for removing old
		items). */
	int m_nWindowMenuItems;
	
	/** A counter for creating unique tab captions for new files. */
	int m_nNewFiles;
	
	int getModifiedFilesCount();
		
private slots:
	void slotCurrentChanged(QWidget*);
	void slotAttachFile(EditorPage*, const QString&);
	void slotNewFile(EditorPage*);
/*
	void slotFileModified(EditorPage*, bool);
	void slotInitiateDrag(QWidget*);
	void slotFillWindowMenu();
	void slotSetCurrentPage(int);
*/
};
} // namespace kscope4
#endif
// Tue Mar 27 19:47:05 PDT 2012
