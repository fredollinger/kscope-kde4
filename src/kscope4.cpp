#include <kparts/part.h>
#include "kscope4.h"
#include "editormanager.h"
#include "editorpage4.h"
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>

KScope::KScope(QWidget *){
	KTextEditor::Editor *editor = KTextEditor::EditorChooser::editor();
	m_doc = editor->createDocument(0);
   	m_view = qobject_cast<KTextEditor::View*>(m_doc->createView(this));
	setCentralWidget(m_view);
}

/*
KScope::~KScope()
{}
*/

// Sun Mar 13 18:31:33 UTC 2011
