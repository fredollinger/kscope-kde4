#define VERSION 0.1

#include <KAboutData>
#include <KCmdLineArgs>
#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>
#include <KApplication>
#include <KMessageBox>
#include <KLocale>

// BEGIN KSCOPE OBJ
#include<k3dockwidget.h>
#include "kscope4.h"
// END KSCOPE OBJ

/**
 * Defines the programme's entry point.
 * Creates KScope's main window, and starts the event loop.
 * @param	argc	Number of command line arguments
 * @param	argv	Command line arguments
 * @return	Programme's exit value
 */
int main(int argc, char *argv[])
{

       // BEGIN Create the "About" dialogue
	//"KScope\nA source-editing environment for KDE, based on " "Cscope"
	KAboutData aboutData( "kscope-kde4", 0,
		ki18n("KScope\nA source-editing environment for KDE, based on Cscope ")
		, "1.0",
		ki18n("CScope Wrapper for KDE4"),
		KAboutData::License_GPL,
		ki18n("Copyright (c) 2007-2007, Elad Lahav (elad_lahav@users.sf.net)") );

	aboutData.addCredit(ki18n("Fred Ollinger"), ki18n("Port to KDE4"),
                "follinge@gmail.com", "http://fredollinger.com");

	aboutData.addAuthor(ki18n("Elad Lahav"), ki18n("Developer"),
		"elad_lahav@users.sf.net", "");

   	aboutData.addCredit(ki18n("Albert Yosher"),
                ki18n("Code completion, patches and bug fixes"),
		"ayosher@users.sf.net", "");

	aboutData.addCredit(ki18n("Gabor Fekete"), ki18n("Bug fixes and patches"), "feketgai@index.hu", "");
        // END Create the "About" dialogue

        // BEGIN CMD LINE ARGS
	KCmdLineArgs::init( argc, argv, &aboutData );
	KCmdLineOptions options;
	options.add("+[CSCOPE.OUT path]", ki18n("Opens a cscope.out file in a temporary project"));
	options.add("+[CSCOPE.PROJ path | KScope project directory path]", ki18n("Opens a KScope project"));
        // END CMD LINE ARGS

	KApplication app;

	//K3DockMainWindow window = new K3DockMainWindow();
	KScope* pKScope = new KScope();

	pKScope->verifyCscope();

	pKScope->show();

	return app.exec();
}

// Mon Mar 28 00:05:40 UTC 2011
