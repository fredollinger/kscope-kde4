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
	void open(const QString&);
	void save();
	bool close(bool bForce = false);

private:
	void initMainWindow();
	void setupActions();
	KParts::ReadWritePart *m_part;
   	KTextEditor::View *m_view;
	KTextEditor::Document *m_doc;

private slots:
	void openFile();

//friend class KScopeActions;
};

#endif
