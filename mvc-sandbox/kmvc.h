#ifndef KMVC_H
#define KMVC_H
#include <KParts/MainWindow>
#include <QtGui/QKeyEvent>
#include <qtimer.h>
#include <kcmdlineargs.h>
#include <kparts/part.h>

/*
// class ProjectManager;
class EditorTabs;
// class FileView;
// class FileList;
class QueryWidget;
class EditorManager;
class CscopeFrontend;
class EditorPage;
// class ProgressDlg;
class CscopeMsgDlg;
class MakeDlg;
class CallTreeManager;
class KScopeActions;
*/

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

namespace kmvc{
//class KScope : public K3DockMainWindow
class kmvc : public KParts::MainWindow
// class KScope 
{
Q_OBJECT

public:
	kmvc(QWidget *parent=0);
	// ~kmvc();
	void openProject(const QString&);
	void open(const QString&);
	void save();
	bool close(bool bForce = false);
	void verifyCscope();

private:
	void initCscope();
	void initMainWindow();
	void setupActions();
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

	/** A project manager used to load projects and read their properties. */
	// ProjectManager* m_pProjMgr;

	/** The file selection widget (project file list and OS file system
		tree.) */
	// FileView* m_pFileView;
	
	/** Pointer to the file list part of the FileView widget. */
	// FileList* m_pFileList;

	/** A progress dialogue that is displayed when building the database for
		the first time. */
	// ProgressDlg* m_pProgressDlg;

	// Manages menu and tool-bar commands.
	// KScopeActions* m_pActions;


private slots:
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
	*/

//friend class KScopeActions;
};
} // namespace kscope

#endif // KMVC