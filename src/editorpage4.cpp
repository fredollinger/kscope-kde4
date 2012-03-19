#include <kdeversion.h>

//#include <Q3PtrList>
#include <qfileinfo.h>
#include <QHBoxLayout>

#include <KTextEditor/MarkInterface>
#include <KTextEditor/View>

#include "editorpage4.h"
#include "filelistlocation.h"
#include "kscopeconfig4.h"

/**
 * Class constructor.
 * @param	pDoc	The document object associated with this page
 * @param	pMenu	A Cscope queries popup menu to use with the editor
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
namespace kscope4{
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

void EditorPage::getBookmarks(FileListLocation& fll)
{
	KTextEditor::MarkInterface* pMarkIf;
	QHash<int, KTextEditor::Mark*> plMarks;
	KTextEditor::Mark* pMark;
	
	// Get the marks interface
	pMarkIf = dynamic_cast<KTextEditor::MarkInterface*>(m_pDoc);
	if (!pMarkIf)
		return;
	
	// Find all bookmarks
	plMarks = pMarkIf->marks();

	QHashIterator<int, KTextEditor::Mark*> i(plMarks);
 	while (i.hasNext()) {
     		i.next();
		fll.append(getFilePath(), i.key(), 0);
 	}
	
	/*
	for (pMark = plMarks.first(); pMark; pMark = plMarks.next()) {
		if (pMark->type == KTextEditor::MarkInterface::markType01)
			fll.append(new FileLocation(getFilePath(), pMark->line, 0));
	}
	*/

}
/** 
 * Returns the full path of the file being edited.
 * @return	The path of the file associated with the Document object, empty 
 *			string if no file is currently open
 */
QString EditorPage::getFilePath()
{
	return m_pDoc->url().path();
}

/**
 * Returns the current position of the cursor.
 * @param	nLine	Holds the line on which the cursor is currently located
 * @param	nCol	Holds the column on which the cursor is currently located
 * @return	true if successful, false otherwise (cursor interface was not
 *			obtained)
 */
bool EditorPage::getCursorPos(int& nLine, int& nCol)
{
	KTextEditor::View* pCursorIf;
	
	// Acquire the view cursor
	pCursorIf = dynamic_cast<KTextEditor::View*>(m_pView);
	if (pCursorIf == NULL)
		return false;
	
	// Get the cursor position (adjusted to 1-based counting)
	//pCursorIf->cursorPosition(&nLine, &nCol);
	pCursorIf->cursorPosition().position(nLine, nCol);
	nLine++;
	nCol++;
	
	return true;
}


} // namespace kscope4
// Sun Mar 18 11:43:51 PDT 2012
