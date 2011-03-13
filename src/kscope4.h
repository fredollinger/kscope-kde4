#ifndef KSCOPE4_H
#define KSCOPE4_H
#include <KParts/MainWindow>
#include <QtGui/QKeyEvent>
#include <qtimer.h>
#include <kcmdlineargs.h>
#include <kparts/part.h>
// #include<k3dockwidget.h>

class ProjectManager;
class EditorTabs;
class FileView;
class FileList;
class QueryWidget;
class EditorManager;
class CscopeFrontend;
class EditorPage;
class ProgressDlg;
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

//class KScope : public K3DockMainWindow
class KScope : public KParts::MainWindow
// class KScope 
{
Q_OBJECT

public:
	KScope(QWidget *parent=0);
	void openProject(const QString&);
	// ~KScope();

private:
	void initMainWindow();
	void setupActions();
	KParts::ReadWritePart *m_part;
   	KTextEditor::View *m_view;
	KTextEditor::Document *m_doc;
};

	/*
	void openProject(const QString&);
	void openLastProject();
	bool openCscopeOut(const QString&);
	void parseCmdLine(KCmdLineArgs *pArgs);
	void verifyCscope();
	*/

// public slots:
//	void slotClose();

//protected:
	//virtual bool queryClose();

// private slots:
	// void clear();
	// void openFile();

	// Menu actions
	/*
	void slotNewFile();
	void slotOpenFile();
	void slotCloseEditor();
	void slotCreateProject();
	void slotOpenProject();
	void slotProjectFiles();
	void slotProjectProps();
	void slotProjectCscopeOut();
	bool slotCloseProject();
	void slotQueryReference();
	void slotQueryDefinition();
	void slotQueryCalled();
	void slotQueryCalling();
	void slotQueryText();
	void slotQueryPattern();
	void slotQueryFile();
	void slotQueryIncluding();
	void slotQueryQuickDef();
	void slotCallTree();
	void slotRebuildDB();
	void slotHistoryShow();
	void slotShortcuts();
	void slotConfigure();
	void slotCloseAllWindows();
	void slotExtEdit();
	void slotCompleteSymbol();
	void slotShowWelcome();
	void slotGotoTag();
	void slotProjectMake();
	void slotProjectRemake();
	void slotShowBookmarks();
	
	// Other slots
	void slotProjectFilesChanged();
	void slotFilesAdded(const QStringList&);
	void slotQuery(uint, bool);
	void slotDeleteEditor(EditorPage*);
	void slotChangeEditor(EditorPage*, EditorPage*);
	void slotShowEditor(const QString&, uint);
	void slotFileOpened(EditorPage*, const QString&);
	void slotFileSaved(const QString&, bool);
	void slotCscopeError(const QString&);
	void slotBuildProgress(int, int);
	void slotBuildInvIndex();
	void slotBuildFinished(uint);
	void slotBuildAborted();
	void slotApplyPref();
	void slotShowCursorPos(uint, uint);
	void slotQueryShowEditor(const QString&, uint);
	void slotDropEvent(QDropEvent*);
	void slotCscopeVerified(bool, uint);

private:
	void initMainWindow();
	void setupActions();
	//KTextEditor::View *m_view;
	//KTextEditor::Document *m_doc;

*/

	/** A project manager used to load projects and read their properties. */
	// ProjectManager* m_pProjMgr;
	
	/** The editors tabbed window. */
	// EditorTabs* m_pEditTabs;
	
	/** The file selection widget (project file list and OS file system
		tree.) */
	// FileView* m_pFileView;
	
	/** Pointer to the file list part of the FileView widget. */
	// FileList* m_pFileList;
	
	/** The query results tabbed window. */
	// QueryWidget* m_pQueryWidget;
	
	/** A KDE editor part manager, responsible for creating KTextEditor
		parts. */
	// EditorManager* m_pEditMgr;
	
	/** A Cscope process for building the database. */
	// CscopeFrontend* m_pCscopeBuild;

	/** A timer for rebuilding the database after a file has been saved. */
	// QTimer m_timerRebuild;
	
	/** Whether the query window should be hidden after the user selects an
		item. */	
	// bool m_bHideQueryOnSelection;
	
	/** The file view docking area. */
	// KDockWidget* m_pFileViewDock;
	
	/** The query window docking area. */
	// KDockWidget* m_pQueryDock;

	/** A persistent dialog used to display error messages from Cscope. */
	// CscopeMsgDlg* m_pMsgDlg;
	
	/** The path of the file currently being edited. */
	// QString m_sCurFilePath;
	
	/** The line number of the current cursor position. */
	// int m_nCurLine;
	
	/** Creates and maintains call tree dialogues. */
	// CallTreeManager* m_pCallTreeMgr;
	
	/** A progress dialogue that is displayed when building the database for
		the first time. */
	// ProgressDlg* m_pProgressDlg;
	
	/** A flag indicating whether the GUI of the embedded editor should be
		merged with that of KScope's. Can be turned off to save time when
		loading/closing a number of editor parts. */
	// bool m_bUpdateGUI;
	
	/** Set to true after a shell script has verified that Cscope is installed
		and correctly configured on this system.
		No Cscope operations should be run if this flag is set to false. */
	// bool m_bCscopeVerified;
	
	/**
	 * Used to postpone rebuilding of the database, until Cscope is ready.
	 */
	// bool m_bRebuildDB;
	
	/**
	 * A widget for running make.
	 */
	// MakeDlg* m_pMakeDlg;
	
	/**
	 * Manages menu and tool-bar commands.
	 */
	/*
	KScopeActions* m_pActions;
	
	void initMainWindow();
	void initCscope();
	bool getSymbol(uint&, QString&, bool&, bool bPrompt = true);
	EditorPage* addEditor(const QString&s);
	EditorPage* createEditorPage();
	inline bool isAutoRebuildEnabled();
	void restoreSession();
	void toggleQueryWindow(bool);
	
	friend class KScopeActions;
	*/
//};
#endif
