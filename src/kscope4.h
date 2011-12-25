#ifndef KSCOPE4_H
#define KSCOPE4_H

#include <kcmdlineargs.h>
#include <KParts/MainWindow>
#include <kparts/part.h>

#include <QDockWidget>
#include <QStringListModel>
#include <QtGui/QKeyEvent>
#include <QListWidget>

#include <qtimer.h>

#include "buildFrontEnd.h"
#include "kdockwidget4.h"
#include "projectbase4.h"
//#include "projectmanager4.h"
// #include "fileview4.h"
#include "querywidget4.h"
#include "progressdlg4.h"
#include "vcsCommitDlg.h"

class ProjectManager;
class EditorTabs;
// class FileView;
// class FileList;
// class QueryWidget;
class EditorManager;
class CscopeFrontend;
class EditorPage;
// class ProgressDlg;
class CscopeMsgDlg;
class MakeDlg;
class CallTreeManager;
class KScopeActions;

/**
 * Defines the main window of KScope.
 * The main window has both UI and functional tasks. As a window, it is
 * composed of three parts:
 * 1. The editing area (EditorTabs - a tab widget with editor pages)
 * 2. The project pane (FileList - listing the files in the project)
 * 3. The query pane (QueryWidget - a tab widget with pages displaying query
 *    results in lists)
 * The main window also maintains the main menu, the toolbar and the status-
 * bar, and is responsible for handling all the actions connected to these
 * bars.
 * As the application's main class, it is responsible for managing projects
 * (using a ProjectManager object) and for running instances of Cscope
 * (through a CscopeFrontend object).
 * @author Elad Lahav
 */

namespace KTextEditor
{
	class Document;
	class View;
}

namespace kscope4{
//class KScope : public K3DockMainWindow
class KScope : public KParts::MainWindow
// class KScope 
{
Q_OBJECT

public:
	KScope(QWidget *parent=0);
	~KScope();
	bool close(bool bForce = false);
	bool noOpenProject();
	void open(const QString&);
	void openFileNamed(QString);
	void openProject(const QString&);
	void save(void);
	void verifyCscope(void);
	QString getSourceRoot(void);

private:
	vcsFrontEnd *m_pVcs;
	buildFrontEnd *m_pBuild;

     	// QDockWidget *resDock;
	/*
    	QListView *listView;
	QStringList m_list;
	QStringListModel *m_model;
	*/

	vcsCommitDlg *m_pVcsCommit;

	QListWidget *customerList;
	/**
	 * Manages menu and tool-bar commands.
	 */
	KScopeActions* m_pActions;

	/** The query window docking area. */
	// KDockWidget* m_pQueryDock;
	KDockWidget* m_pQueryDock;

	/** A Cscope process for building the database. */
	CscopeFrontend* m_pCscopeBuild;

	/** The query results tabbed window. */
	QueryWidget* m_pQueryWidget;

	/** Creates and maintains call tree dialogues. */
	CallTreeManager* m_pCallTreeMgr;

	/** Whether the query window should be hidden after the user selects an
		item. */	
	bool m_bHideQueryOnSelection;

	KParts::ReadWritePart *m_part;
   	KTextEditor::View *m_view;
	KTextEditor::Document *m_doc;

	/** A persistent dialog used to display error messages from Cscope. */
	CscopeMsgDlg* m_pMsgDlg;

	/** Set to true after a shell script has verified that Cscope 
		is installed
		and correctly configured on this system.
		No Cscope operations should be run if this flag is set to false. 	*/
	bool m_bCscopeVerified;

	/**
	 * Used to postpone rebuilding of the database, until Cscope is ready.
	 */
	bool m_bRebuildDB;

	/** A project manager used to load projects and read their properties. */
	ProjectManager* m_pProjMgr;

	/** The file selection widget (project file list and OS file system
		tree.) */
	// FileView* m_pFileView;
	
	/** Pointer to the file list part of the FileView widget. */
	// FileList* m_pFileList;

	/** A progress dialogue that is displayed when building the database for
		the first time. */
	ProgressDlg* m_pProgressDlg;

	// Manages menu and tool-bar commands.
	// KScopeActions* m_pActions;

	// BEGIN PRIVATE FUNCTION PROTOTYPES
	bool getSymbol(uint&, QString&, bool&, bool bPrompt = true);
	void initCscope();
	void initMainWindow();
	bool openCscopeOut(const QString&);
	void setupActions();
	void toggleQueryWindow(bool bShow);
	void createDockWindows();
	// END PRIVATE FUNCTION PROTOTYPES


private slots:
	void slotQuery(uint, bool);
	void slotQueryPattern();

	// Other slots
	void slotBuildProgress(int, int);
	void slotBuildInvIndex();
	void slotBuildFinished(uint);
	void slotBuildAborted();
	void slotCscopeError(const QString&);

	// BEGIN Menu actions
	// BEGIN Version Control Actions
	void slotCommit(void);	
	void slotDiffDone(int i, QProcess::ExitStatus es);
	void slotDiffReady(void);	
	void slotPull(void);	
	void slotPush(void);	
	void slotDiff(void);	
	// END Version Control Actions

	void openFile(void);
	void slotOpenProject();
	void slotConfigure(void);
	void slotCscopeVerified(bool, uint);
	void slotRebuildDB(void);
	void slotCreateProject(void);
	bool slotCloseProject(void);
	bool slotBuildProject(void);
	bool slotBuildReady(void);
	// END Menu actions

}; //class Kscope
} // namespace kscope

#endif // KSCOPE4_H

// Sat Oct 29 09:00:02 PDT 2011
