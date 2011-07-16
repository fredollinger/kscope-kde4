#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <kmessagebox.h>
#include <klocale.h>
#include <kconfigbase.h>
#include <KConfigGroup>
#include <KConfig>
#include "project4.h"
#include "projectbase4.h"
#include "kscopeconfig4.h"
#include "cscopefrontend4.h"
#include <qdebug.h>

#define PROJECT_CONFIG_VER 4

/**
 */
// Project::Project() : ProjectBase(), m_pConf(NULL)
 Project::Project() : ProjectBase()
{
}

/**
 */
Project::~Project()
{
	// close();
}

void Project::writeOptions(KConfig* pConf, const Options& opt)
{
	qDebug() << "Project::writeOptions() stub \n";
	// ORIG: pConf->setGroup("Project");
	KConfigGroup gp(pConf, "Project");

	gp.writeEntry("RootPath", opt.sSrcRootPath);
	gp.writeEntry("FileTypes", opt.slFileTypes.join(" "));
	gp.writeEntry("Kernel", opt.bKernel);
	gp.writeEntry("InvIndex", opt.bInvIndex);		
	gp.writeEntry("NoCompress", opt.bNoCompress);		
	gp.writeEntry("SlowPathDef", opt.bSlowPathDef);		
	gp.writeEntry("AutoRebuildTime", opt.nAutoRebuildTime);
	gp.writeEntry("TabWidth", opt.nTabWidth);
	gp.writeEntry("CtagsCommand", opt.sCtagsCmd);
	
	// Set auto-completion options
	/*
	pConf->setGroup("AutoCompletion");
	pConf->writeEntry("Enabled", opt.bACEnabled);
	pConf->writeEntry("MinChars", opt.nACMinChars);
	pConf->writeEntry("Delay", opt.nACDelay);
	pConf->writeEntry("MaxEntries", opt.nACMaxEntries);
	*/
	return;
}

/**
 * Creates a project by writing a configuration file inside the given
 * directory.
 * @param	sName	The project's name
 * @param	sPath	The full path of the project's directory
 * @param	opt		Project options
 */
bool Project::create(const QString& sName, const QString& sPath,
	const Options& opt)
{
	// Prepare the project's files
	KConfig conf(sPath + "/cscope.proj");

	// Write the configuration file version
	// conf.setGroup("");
	KConfigGroup groupVersion(&conf, "Version");
	groupVersion.writeEntry("Version", PROJECT_CONFIG_VER);
	
	// Write project properties in the configuration file
	// conf.setGroup("Project");
	KConfigGroup groupProject(&conf, "Project");
	//conf.writeEntry("Name", sName);
	groupProject.writeEntry("Name", sName);
	writeOptions(&conf, opt);
	
	// Flush the config file data, so the project is created even if KScope
	// crashes...
	conf.sync();

	return true;
}

// Sat Jul 16 17:36:26 UTC 2011
