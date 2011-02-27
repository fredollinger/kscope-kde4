#include "kscope4.h"
#include <kparts/part.h>

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
*/

KScope::KScope(QWidget *)
// KScope::KScope()
{

	//KParts::ReadWritePart *m_part;
	*m_part = new KParts::ReadWritePart();
	setCentralWidget(m_part->widget());
	
	// BEGIN KSCOPE ORIG
	// QString sPath;

	// END KSCOPE ORIG
}

/*
KScope::~KScope()
{}
*/

// Sun Feb  6 03:14:42 UTC 2011

