#ifndef FILELIST_H
#define FILELIST_H

#include "listviewitem4.h"
#include <qwidget.h>
#include "searchlist4.h"
#include "projectmanager4.h"

/**
 * Implements a searchable list of files.
 * The file list is composed of a list view, and a search box, into which the
 * user can enter a file name. The name is matched against the contents of
 * the list, and matching items are selected.
 * @author Elad Lahav
 */

class FileList : public SearchList, public FileListTarget
{
	Q_OBJECT

public: 
	FileList(QWidget* pParent = 0, const char* szName = 0);
	~FileList();
	
	virtual void addItem(const QString&);
	bool findFile(const QString&);
	void clear();
	void applyPrefs();
	void setRoot(const QString&);
	virtual bool getTip(ListViewItem*, QString&);
	
signals:
	/**
	 * Emitted when a file is selected, by either double-clicking a list
	 * item, or by highlighting an item and pressing the ENTER key.
	 * @param	sPath	The full path of the selected file
	 * @param	nLine	Line number, always set to 0
	 */
	void fileRequested(const QString& sPath, uint nLine);

protected:
	virtual void processItemSelected(ListViewItem*);
	
private:
	/** A common root path for all items in the list. */
	QString m_sRoot;
};

#endif
