#include <qfileinfo.h>
#include <kdeversion.h>
#include "editorpage4.h"
#include "kscopeconfig4.h"
#include <QHBoxLayout>

/**
 * Class constructor.
 * @param	pDoc	The document object associated with this page
 * @param	pMenu	A Cscope queries popup menu to use with the editor
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
EditorPage::EditorPage(KTextEditor::Document* pDoc, 
	QTabWidget* pParent, const char* szName) : QHBoxLayout(pParent),
	m_pParentTab(pParent),
	m_pDoc(pDoc),
	m_bOpen(false),
	m_bNewFile(false),
	m_sName(""),
	m_bWritable(true), /* new documents are writable by default */
	m_bModified(false),
	m_nLine(0),
	m_bSaveNewSizes(false)
{
}

/**
 * Class destructor.
 */
EditorPage::~EditorPage()
{
}

