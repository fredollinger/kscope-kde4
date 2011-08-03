#include <kparts/part.h>
#include <KStandardAction>
#include <KActionCollection>
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>
#include <KXMLGUIFactory>
#include <KFileDialog>
#include <KStatusBar>
#include <KMessageBox>
#include <qdebug.h>
#include "kmvc.h"
#include <QStringList>
#include <QStringListModel>

namespace kmvc{
kmvc::kmvc(QWidget *)
{
	m_view = new QStringListModel();
	setCentralWidget(m_view);
	// initMainWindow();
}

/**
 * Class destructor.
 */
/*
kmvc::~KMVC()
{
}
*/

void kmvc::setupActions()
{
}

void kmvc::initMainWindow()
{
	KStatusBar* pStatus;

	// Create the status bar
	pStatus = statusBar();
	pStatus->insertItem(i18n(" Line: N/A Col: N/A "), 0, 0);

	return;
}
} // namespace kmvc

// Sun Jul 31 08:48:30 PDT 2011
