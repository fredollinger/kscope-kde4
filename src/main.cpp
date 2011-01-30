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

static const char *description =
        I18N_NOOP("KScope\nA source-editing environment for KDE, based on "
        "Cscope");

/*
   KCmdLineOptions &  add (const QByteArray &name, const KLocalizedString
                      &description=KLocalizedString(), const QByteArray
                      &defaultValue=QByteArray())
*/

	//static KCmdLineOptions options; 
	static KCmdLineOptions *options = new KCmdLineOptions();
	//Kscope* window = new Kscope();
	//options.add("+[CSCOPE.OUT path]",
		//I18N_NOOP("Opens a cscope.out file in a temporary project"), 0);
/*
{
        { "+[CSCOPE.OUT path]",
                I18N_NOOP("Opens a cscope.out file in a temporary project"), "" 
	}
//, { "+[CSCOPE.PROJ path | KScope project directory path]",
 //               I18N_NOOP("Opens a KScope project"), 0 }
	//, KCmdLineLastOption
};
*/

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
	KAboutData aboutData( "kscope-kde4", 0,
		ki18n("CScope Wrapper for KDE4"), "1.0",
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
	KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
	KCmdLineArgs::init( argc, argv, &aboutData );
	//KCmdLineArgs::addCmdLineOptions(options);
        // BEGIN CMD LINE ARGS

	//KScope* window = new KScope();
	//window->show();

	KApplication app;

	Kscope* window = new Kscope();
	window->show();

	return app.exec();
}
