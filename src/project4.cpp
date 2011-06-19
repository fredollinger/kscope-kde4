#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <kmessagebox.h>
#include <klocale.h>
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
