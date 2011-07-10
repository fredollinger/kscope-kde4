#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QTreeWidgetItem>
#include <QtGui/QDialog>
#include <kfiletreeview.h>
#include <kfiletreebranch.h>
#include "fileviewlayout4.h"

/**
 * A tabbed widget that contains a file list and a file tree.
 * The list is an object of type FileList, which displays all files included
 * in the current project. The tree is a standard KFileTreeView, which can
 * browse through the entire file system. Optionally, the root of the tree
 * can be set per project.
 * @author Elad Lahav
 */

class FileView : public QDialog, public Ui::FileViewLayout
{
	Q_OBJECT

public:
	FileView(QWidget* pParent = 0, const char* szName = 0, Qt::WFlags fl = 0);
	~FileView();

	/**
	 * @return	The file list widget which is a child of this widget.
	 */
	FileList* getFileList() { return m_pFileList; }
	
	void setRoot(const QString&);
	void clear();
	
signals:
	/**
	 * Emitted when a file is selected, by either double-clicking a list
	 * item, or by highlighting an item and pressing the ENTER key.
	 * @param	sPath	The full path of the selected file
	 * @param	nLine	Line number, always set to 0
	 */
	void fileRequested(const QString& sPath, uint nLine);

private:
	/** The current branch in the file tree. */
	KFileTreeBranch* m_pCurBranch;

	/** The current root of the file tree. */
	QString m_sRoot;
	
private slots:
	void slotTreeItemSelected(QTreeWidgetItem*);
};

#endif

