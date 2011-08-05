#ifndef KMVC_H
#define KMVC_H
#include <KParts/MainWindow>
#include <QtGui/QKeyEvent>
#include <qtimer.h>
#include <kcmdlineargs.h>
#include <kparts/part.h>
#include <QStringList>
#include <QStringListModel>

namespace KTextEditor
{
	class Document;
	class View;
}

namespace kmvc{
class kmvc : public KParts::MainWindow
{
Q_OBJECT

public:
	kmvc(QWidget *parent=0);
	void openProject(const QString&);
	void open(const QString&);
	void save();
	bool close(bool bForce = false);
	void verifyCscope();
	void setupActions(void);

private:
	void initCscope(void);
	void initMainWindow(void);
	bool openCscopeOut(const QString&);
	KParts::ReadWritePart *m_part;
   	KTextEditor::View *m_view;
	KTextEditor::Document *m_doc;


	/** A persistent dialog used to display error messages from Cscope. */
	// CscopeMsgDlg* m_pMsgDlg;

	/** Set to true after a shell script has verified that Cscope 
		is installed
		and correctly configured on this system.
		No Cscope operations should be run if this flag is set to false. 	*/
	bool m_bCscopeVerified;

	/**
	 * Used to postpone rebuilding of the database, until Cscope is ready.
	 */
	bool m_bRebuildDB;

   	QStringListModel *gslmFiles;

private slots:

};
} // namespace kmvc

#endif // KMVC
