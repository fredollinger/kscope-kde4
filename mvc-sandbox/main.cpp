#define VERSION 0.1

#include <KAboutData>
#include <KCmdLineArgs>
#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>
#include <KApplication>
#include <KMessageBox>
#include <KLocale>

// BEGIN MVC INCLUDES
#include <QStringListModel>
#include <QStringList>
// END MVC INCLUDES

// BEGIN KSCOPE OBJ
#include<k3dockwidget.h>
#include "KmvcDlg.h"
// END KSCOPE OBJ

int main(int argc, char *argv[])
{
       // BEGIN Create the "About" dialogue
	KAboutData aboutData( "kscope-kde4", 0,
		ki18n("KMVC: An MVC Sandbox\n")
		, "1.0",
		ki18n("MVC Sandbox"),
		KAboutData::License_GPL,
		ki18n("Copyright (c) 2011, Fred Ollinger (follinge@gmail.com)") );

		aboutData.addCredit(ki18n("Fred Ollinger"), ki18n("Lead Developer"),
                "follinge@gmail.com", "http://fredollinger.com");
        // END Create the "About" dialogue

        // BEGIN CMD LINE ARGS
	KCmdLineArgs::init( argc, argv, &aboutData );
	KCmdLineOptions options;
	options.add("+[CSCOPE.OUT path]", ki18n("Opens a cscope.out file in a temporary project"));
	options.add("+[CSCOPE.PROJ path | KScope project directory path]", ki18n("Opens a KScope project"));
        // END CMD LINE ARGS

	KApplication app;

	// kscope4::KScope* pKScope = new kscope4::KScope();
	KmvcDlg* pK =  new KmvcDlg();
	// pK = new KmvcDlg::KmvcDlg();
	// KmvcDlg::KmvcDlg(QWidget* pParent, const char* szName) 

	pK->show();

	return app.exec();
}

// Sun Sep 25 10:16:50 PDT 2011
