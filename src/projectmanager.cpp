#include <kmessagebox.h>
#include <klocale.h>
#include "projectmanager.h"
#include "project.h"
#include "kscopeconfig.h"

/**
 * Class constructor.
 */
ProjectManager::ProjectManager() : m_pCurProj(NULL), projectIsOpen(false)
{
}

/**
 * Class destructor.
 */
ProjectManager::~ProjectManager()
{
	close();
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
	
	// Handle requests for a hidden .cscope directory
	if (dir.dirName() == ".cscope") {
		sParentPath = QDir::cleanDirPath(dir.absPath());
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
	if (!dir.mkdir(sDirName, false) || !dir.cd(sDirName, false)) {
		sMsg = i18n("Failed to create the project directory (%1/%2)").
			arg(dir.canonicalPath()).arg(sDirName);
		KMessageBox::error(0, sMsg);
		return false;
	}
	
	if (!Project::create(sName, dir.absPath(), opt))
		return false;
	
	sProjDir = dir.path();
	return true;
}

/**
 * Opens a project and makes it the current one.
 * @param	sPath	The directory containing the project's files
 * @return	true if successful, false otherwise
 */
bool ProjectManager::open(const QString& sPath)
{
	Project* pProj;
	
	// Close the current project
	close();
	
	// Try to open the new project
	pProj = new Project();
	if (!pProj->open(sPath)) {
		delete pProj;
		return false;
	}
	
	// Add to the list of recently opened projects
	Config().addRecentProject(sPath);
	
	// Project opened successfully
	m_pCurProj = pProj;

	projectIsOpen = true;
	return true;
}

/**
 * Opens a Cscope.out file as a temporary project.
 * @param	sFilePath	The full path of the Cscope.out file
 * @return	true if successful, false otherwise
 */
bool ProjectManager::openCscopeOut(const QString& sFilePath)
{
	ProjectBase* pProj;
	
	// Close the current project
	close();
	
	// Try to open the new project
	pProj = new ProjectBase();
	if (!pProj->open(sFilePath)) {
		delete pProj;
		return false;
	}
	
	// Add to the list of recently opened projects
	Config().addRecentProject(sFilePath);
	
	// Project opened successfully
	m_pCurProj = pProj;
	return true;	
}

/**
 * Performs clean-up on the project's variables, and detaches the associated
 * directory.
 */
void ProjectManager::close()
{
	projectIsOpen = false;
	if (m_pCurProj) {
		delete m_pCurProj;
		m_pCurProj = NULL;
	}
}

QString ProjectManager::getProjName() const
{
	if (!m_pCurProj)
		return i18n("No Project");
		
	return m_pCurProj->getName();
}
