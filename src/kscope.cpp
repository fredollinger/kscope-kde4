/***************************************************************************
 *
 * Copyright (C) 2005 Elad Lahav (elad_lahav@users.sourceforge.net)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ***************************************************************************/
#include "kscope.h"
#include "editormanager.h"

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
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>

#include <kaction.h>
#include <kactioncollection.h>
#include <kconfig.h>
#include <kedittoolbar.h>
#include <kfiledialog.h>
#include <kshortcutsdialog.h>
#include <klibloader.h>
#include <kmessagebox.h>
#include <kservice.h>
#include <kstandardaction.h>
#include <kstatusbar.h>
#include <kurl.h>
*/

KScope::KScope(QWidget *)
{

// BEGIN KSCOPE ORIG
	QString sPath;

	//Config().load();

	initMainWindow();

// END KSCOPE ORIG

// BEGIN BOILERPLATE KATE
KTextEditor::Editor *editor = KTextEditor::EditorChooser::editor();

if (!editor) {
	KMessageBox::error(this, i18n("A KDE text-editor component could not be found;\n" "please check your KDE installation."));

	kapp->exit(1);
}

m_doc = editor->createDocument(0);
m_view = qobject_cast<KTextEditor::View*>(m_doc->createView(this));

setCentralWidget(m_view);
setupActions();

setXMLFile("editorui.rc");
createShellGUI(true);

guiFactory()->addClient(m_view);

show ();
// END BOILERPLATE KATE
}

void KScope::setupActions()
{
KStandardAction::quit(kapp, SLOT(quit()), actionCollection());
KStandardAction::open(this, SLOT(openFile()), actionCollection());
KStandardAction::clear(this, SLOT(clear()), actionCollection());
}

void KScope::clear()
{
m_doc->clear();
}

void KScope::openFile()
{
	m_view->document()->openUrl(KFileDialog::getOpenFileName());
}


/**
 * Reports the results of the Cscope verification script.
 * This slot is connected to the done() signal emitted by the CscopeVerifier
 * object constructed in verifyCscope().
 */
/*
void KScope::slotCscopeVerified(bool bResult, uint nArgs)
{
	statusBar()->message(i18n("Verifying Cscope installation...Done"), 3000);
	
	// Mark the flag even if Cscope was not found, to avoid nagging the user
	// (who may wish to use KScope even with Cscope disabled)
	m_bCscopeVerified = true;

	// Prompt the user in case Cscope is not properly installed
	if (!bResult) {
		KMessageBox::error(0, i18n("Cscope may not be properly installed on "
			"this system.\nPlease check the Cscope path specified in KScope's "
			"configuration dialogue."));
		slotConfigure();
		return;
	}
		
	// Set the discoverred supported command-line arguments
	CscopeFrontend::setSupArgs(nArgs);
	
	// Build the database, if required
	if (m_bRebuildDB) {
		m_bRebuildDB = false;
		slotRebuildDB();
	}
}
*/

/**
 * Positions child widgets into their docking stations, and performs some
 * other main window initialisation.
 */
void KScope::initMainWindow()
{
	KStatusBar* pStatus;
	// KDockWidget* pMainDock;
	// QPopupMenu* pPopup;
	
	/*
	// Create the status bar
	pStatus = statusBar();
	pStatus->insertItem(i18n(" Line: N/A Col: N/A "), 0, 0, true);

	// Create the main dock for the editor tabs widget
	pMainDock = createDockWidget("Editors Window", QPixmap());
	pMainDock->setWidget(m_pEditTabs);
	pMainDock->setDockSite(KDockWidget::DockCorner);
	setMainDockWidget(pMainDock);
	setView(pMainDock);
	pMainDock->setEnableDocking(KDockWidget::DockNone);

	// Create the query window dock
	m_pQueryDock->setWidget(m_pQueryWidget);
	m_pQueryDock->manualDock(pMainDock, KDockWidget::DockBottom, 65);

	// Update the relevant shell action when the dock is hidden through its
	// close button
	connect(m_pQueryDock, SIGNAL(headerCloseButtonClicked()), m_pActions,
		SLOT(slotQueryDockClosed()));
		
	// Create the file view dock
	m_pFileViewDock->setWidget(m_pFileView);
	m_pFileViewDock->manualDock(pMainDock, KDockWidget::DockRight, 80);
	
	// Update the relevant shell action when the dock is hidden through its
	// close button
	connect(m_pFileViewDock, SIGNAL(headerCloseButtonClicked()), m_pActions,
		SLOT(slotFileViewDockClosed()));
	
	// Associate the "Window" menu with the editor tabs widdget
	pPopup = (QPopupMenu*)factory()->container("window", this);
	m_pEditTabs->setWindowMenu(pPopup);

	// Associate the "Query" popup menu with the query widget
	pPopup = (QPopupMenu*)factory()->container("query_popup", this);
	m_pQueryWidget->setPageMenu(pPopup, m_pActions->getLockAction());
	
	// Restore dock configuration
	Config().loadWorkspace(this);
	m_bHideQueryOnSelection = m_pQueryDock->isHidden();
	m_pActions->initLayoutActions();
	*/
}

// Sun Feb  6 03:14:42 UTC 2011

