#ifndef CALLTREEMANAGER_H
#define CALLTREEMANAGER_H

#include <qwidget.h>
// FO qptrlist.h is now qvaluelist.h
// #include <qptrlist.h>
#include <QList>

class CallTreeDlg;

/**
 * Manages all call tree dialogs within the project.
 * Responsible for saving/loading of the call tree dialogs.
 * @author Albert Yosher
 */
class CallTreeManager : public QObject
{
   Q_OBJECT
   
public: 
	CallTreeManager(QWidget*);
	~CallTreeManager();
	
	void saveOpenDialogs(const QString&, QStringList&);
	void loadOpenDialogs(const QString&, const QStringList&);
	CallTreeDlg* addDialog();
	void closeAll();
	
signals:
	/**
	 * Emitted when any call tree dialogue sends a request to view a location
	 * in the source code.
	 * @param	sPath	The full path of the file to show
	 * @param	nLine	The line number in this file
	 */
	void lineRequested(const QString& sPath, uint nLine);
	 
private:
	/** The list of open call tree dialogues. */
	QList<CallTreeDlg*> m_lstDialogs;
	
private slots:
	void slotRemoveDialog(const CallTreeDlg*);
};

#endif
