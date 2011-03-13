#include <kparts/part.h>
#include "kscope4.h"
#include "editormanager.h"
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>

/*
#include <KApplication>
#include <KAction>
#include <KLocale>
#include <KActionCollection>
#include <KStandardAction>
#include <KFileDialog>
#include <KMessageBox>
#include <KIO/NetAccess>
#include <KSaveFile>
#include <QTextStream>
#include <KXMLGUIFactory>
*/

KScope::KScope(QWidget *)
// KScope::KScope()
{
	KTextEditor::Editor *editor = KTextEditor::EditorChooser::editor();
	m_doc = editor->createDocument(0);
   	m_view = qobject_cast<KTextEditor::View*>(m_doc->createView(this));
	setCentralWidget(m_view);
	//KParts::ReadWritePart *m_part;
	// *m_part = new KParts::ReadWritePart();
	// setCentralWidget(m_part->widget());
	
	// BEGIN KSCOPE ORIG
	// QString sPath;

	// END KSCOPE ORIG
}

/*
KScope::~KScope()
{}
*/

// Sun Feb  6 03:14:42 UTC 2011

