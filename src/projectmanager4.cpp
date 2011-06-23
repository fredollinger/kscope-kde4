/***************************************************************************
 *
 * Copyright (C) 2005 Elad Lahav (elad_lahav@users.sourceforge.net)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ***************************************************************************/

#include <kmessagebox.h>
#include <klocale.h>
#include "projectmanager4.h"
#include "project4.h"
#include "kscopeconfig4.h"

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

