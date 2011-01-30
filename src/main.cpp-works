#define VERSION 0.1

#include <KAboutData>
#include <KCmdLineArgs>
#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>
#include <KApplication>
#include <KMessageBox>
#include <KLocale>


#include "kscope.h"
#include "mainwindow.h"

/**
 * Defines the programme's entry point.
 * Creates KScope's main window, and starts the event loop.
 * @param	argc	Number of command line arguments
 * @param	argv	Command line arguments
 * @return	Programme's exit value
 */
int main(int argc, char *argv[])
{


KAboutData aboutData( "tutorial2", 0,

ki18n("Tutorial 2"), "1.0",

ki18n("A simple text area"),

KAboutData::License_GPL,

ki18n("Copyright (c) 2007 Developer") );

KCmdLineArgs::init( argc, argv, &aboutData );

	// Create the "About" dialogue

	//KScope* window = new KScope();
	//window->show();

	KApplication app;

	MainWindow* window = new MainWindow();
	window->show();

	return app.exec();
}
