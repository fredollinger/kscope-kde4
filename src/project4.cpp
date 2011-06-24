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
	// Prepare the project's files
	KConfig conf(sPath + "/cscope.proj");
	KConfigGroup confProject(conf, "Project");

	// Write the configuration file version
	// conf.setGroup("");
	conf.writeEntry("Version", PROJECT_CONFIG_VER);
	
	// Write project properties in the configuration file
	// conf.setGroup("Project");
	confGroup.writeEntry("Name", sName);
	writeOptions(&conf, opt); // check this
	
	// Flush the config file data, so the project is created even if KScope
	// crashes...
	conf.sync();
	confGroup.sync();

	return true;
}
