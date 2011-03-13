#include <kparts/part.h>
#include "kscope4.h"
#include <KStandardAction>
#include <KActionCollection>
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>
#include <KXMLGUIFactory>
#include <KFileDialog>

KScope::KScope(QWidget *){
	KTextEditor::Editor *editor = KTextEditor::EditorChooser::editor();
	m_doc = editor->createDocument(0);
   	m_view = qobject_cast<KTextEditor::View*>(m_doc->createView(this));
	setCentralWidget(m_view);

	setupActions();

	// Create the initial GUI (no active part)
	setXMLFile("kscopeui.rc");
	createShellGUI();
	guiFactory()->addClient(m_view);
}

void KScope::setupActions()
{
	// KStandardAction::quit(app, SLOT(quit()), actionCollection());
	KStandardAction::open(this, SLOT(openFile()), actionCollection());
	// KStandardAction::clear(this, SLOT(clear()), actionCollection());

	/*
  	KAction* openAction = new KAction(this);
  	openAction->setText(i18n("&Open"));
  	openAction->setIcon(KIcon("document-new"));
  	openAction->setShortcut(Qt::CTRL + Qt::Key_O);
  	actionCollection()->addAction("openFile", openAction);
  	connect(openAction, SIGNAL(triggered(bool)),
       	   this, SLOT(openFile()));
	*/
}

void KScope::openFile()
{
	m_view->document()->openUrl(KFileDialog::getOpenFileName());	
}

/*
KScope::~KScope()
{}
*/

// Sun Mar 13 18:31:33 UTC 2011
