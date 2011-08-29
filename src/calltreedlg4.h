#ifndef CALLTREEDLG_H
#define CALLTREEDLG_H

#include <qwidget.h>
#include <qlistview.h>
#include "calltreelayout4.h"

/**
 * A multiple-view window showing function call information.
 * The available views are:
 * - Call graph, showing both calling and call functions
 * - Called functions tree
 * - Calling functions tree
 * NOTE: This is class is now derived from QWidget instead of QDialog. This 
 * means that call-trees are independent windows, which can be maximised or
 * minimised.
 * @author Elad Lahav
 */
class CallTreeDlg : public QWidget, public Ui::CallTreeLayout
{
   Q_OBJECT
   
public: 
	CallTreeDlg(QWidget* pParent = 0, const char* szName = 0);
	~CallTreeDlg();
	
	void setRoot(const QString&);
	bool load(const QString&, const QString&);
	void store(const QString&);
	
	/** Returns Call Tree filename */
	QString getFileName() { return m_sFileName; }

public slots:
	virtual void show();

signals:
	/**
	 * Emitted when the user makes a request to view the contents of a
	 * location in the source code.
	 * This can be the location of a call, the definition of a function,
	 * etc.
	 * @param	sPath	The full path of the file to show
	 * @param	nLine	The line number in this file
	 */
	void lineRequested(const QString& sPath, uint nLine);
	
	/**
	 * Emitted when the user closes the tree view.
	 */
	void closed(const CallTreeDlg*);

protected:
	virtual void closeEvent(QCloseEvent*);

protected slots:
	virtual void slotSaveClicked();
	virtual void slotZoomInClicked();
	virtual void slotZoomOutClicked();
	virtual void slotRotateClicked();
	virtual void slotPrefClicked();
	virtual void slotViewChanged(int);
	
private:
	/** The root function. */
	QString m_sRoot;
	
	/** A unique file name used for storing the call tree on a file.
		The name is a combination of the root function and an incremented
		index. */
	QString m_sFileName;
	
	/** The full path of the file on which the call tree was saved 
		(empty if this graph was never stored). */
	QString m_sFilePath;
		
	/** The view to show when the dialogue is first displayed. */
	int m_nDefView;
		
	/** An index for the generating unique file names. */
	static int s_nFileNameIndex;
};

#endif
