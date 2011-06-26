#include <kmessagebox.h>
#include <klocale.h>
#include "projectmanager4.h"
#include "project4.h"
#include "kscopeconfig4.h"
#include <qdebug.h>

/**
 * Class constructor.
 */
ProjectManager::ProjectManager() : m_pCurProj(NULL)
{
}

/**
 * Class destructor.
 */
ProjectManager::~ProjectManager()
{
// 	close();
}

/**
 * Creates a project's directory, and associates this directory with the
 * current object. This directory is created under the given path, and using
 * the project's name (which, thus, has to be a legal file name). 
 * Note: this function attempts to create a new directory, so the given path
 * and name must not lead to an existing one.
 * @param	sName		The project's name
 * @param	sPath		The parent directory under which to create the 
 *						project's directory
 * @param	opt			A structure containing project options
 * @return	true if successful, false otherwise
 */
bool ProjectManager::create(const QString& sName, const QString& sPath, 
	const ProjectBase::Options& opt, QString& sProjDir)
{
	QDir dir(sPath);
	QString sParentPath;
	QString sDirName = sName;
	QString sMsg;
	
	qDebug() << "ProjectManager::create() BEGIN \n";

	// Handle requests for a hidden .cscope directory
	if (dir.dirName() == ".cscope") {
		sParentPath = QDir::cleanPath(dir.absolutePath());
		sParentPath = sParentPath.section('/', 0, -2);
		dir.cd(sParentPath);
		sDirName = ".cscope";
	}
	
	// The parent directory must exist
	if (!dir.exists()) {
		sMsg = i18n("The requested parent directory (%1) does not exist").
			arg(sParentPath);
		KMessageBox::error(0, sMsg);
		return false;
	}
	
	// Make sure the directory doesn't exist
	if (dir.exists(sDirName)) {
		sMsg = i18n("Cannot create a project inside an existing directory "
			"(%1/%2)").arg(dir.canonicalPath()).arg(sDirName);
		KMessageBox::error(0, sMsg);
		return false;
	}

	// Try to create the projcet's directory
	if (!dir.mkdir(sDirName) || !dir.cd(sDirName)) {
		sMsg = i18n("Failed to create the project directory (%1/%2)").
			arg(dir.canonicalPath()).arg(sDirName);
		KMessageBox::error(0, sMsg);
		return false;
	}
	
	if (!Project::create(sName, dir.absolutePath(), opt))
		return false;
	
	sProjDir = dir.path();

	qDebug() << "ProjectManager::create() END \n";
	return true;
}

// Sun Jun 26 20:08:46 UTC 2011
