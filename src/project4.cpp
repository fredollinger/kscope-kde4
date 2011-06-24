#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <kmessagebox.h>
#include <klocale.h>
#include <kconfigbase.h>
#include "project4.h"
#include "projectbase4.h"
#include "kscopeconfig4.h"
#include "cscopefrontend4.h"
#include <qdebug.h>

#define PROJECT_CONFIG_VER 2

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
	/*
	KConfig::KConfig  	(  	const QString &   	 fileName = QString::null,
		bool  	bReadOnly = false,
		bool  	bUseKDEGlobals = true,
		const char *  	resType = "config"	 
	) */	
	// Prepare the project's files
	KConfig conf(sPath + "/cscope.proj");
	// KConfigGroup confProject(&conf, "Project");

	/*
	// Write the configuration file version
	// conf.setGroup("");
	conf->writeEntry("Version", PROJECT_CONFIG_VER);
	
	// Write project properties in the configuration file
	// conf.setGroup("Project");
	confGroup.writeEntry("Name", sName);
	writeOptions(&conf, opt); // check this
	
	// Flush the config file data, so the project is created even if KScope
	// crashes...
	conf.sync();
	confGroup.sync();
	*/

	return true;
}

void Project::writeOptions(KConfig* pConf, const Options& opt)
{
	qDebug() << "Project::writeOptions() stub \n";
	/*
	pConf->setGroup("Project");
	pConf->writeEntry("RootPath", opt.sSrcRootPath);
	pConf->writeEntry("FileTypes", opt.slFileTypes.join(" "));
	pConf->writeEntry("Kernel", opt.bKernel);
	pConf->writeEntry("InvIndex", opt.bInvIndex);		
	pConf->writeEntry("NoCompress", opt.bNoCompress);		
	pConf->writeEntry("SlowPathDef", opt.bSlowPathDef);		
	pConf->writeEntry("AutoRebuildTime", opt.nAutoRebuildTime);
	pConf->writeEntry("TabWidth", opt.nTabWidth);
	pConf->writeEntry("CtagsCommand", opt.sCtagsCmd);
	
	// Set auto-completion options
	pConf->setGroup("AutoCompletion");
	pConf->writeEntry("Enabled", opt.bACEnabled);
	pConf->writeEntry("MinChars", opt.nACMinChars);
	pConf->writeEntry("Delay", opt.nACDelay);
	pConf->writeEntry("MaxEntries", opt.nACMaxEntries);
	*/
	return;
}

// Fri Jun 24 13:47:06 PDT 2011
