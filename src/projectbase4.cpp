/***************************************************************************
 *
 * Copyright (C) 2007 Elad Lahav (elad_lahav@users.sourceforge.net)
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AS IS'' AND ANY EXPRESS OR
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

#include "projectbase4.h"
#include "kscopeconfig4.h"
#include "cscopefrontend4.h"

ProjectBase::ProjectBase()
{
}

ProjectBase::~ProjectBase()
{
}

bool ProjectBase::open(const QString& sPath)
{
	QFileInfo fi(sPath);
		
	// Make sure the file exists, and that is is a cross-reference file
	if (!fi.exists() || !isCscopeOut(fi.absFilePath()))
		return false;
		
	// Set the project's directory
	m_dir = fi.dirPath(true);
	
	// Set the name of the project to be the full path of the file
	m_sName = fi.absFilePath();
	
	// Initialise project options (assume source root is the folder holding the
	// cscope.out file)
	getDefOptions(m_opt);
	m_opt.sSrcRootPath = m_dir.absPath();
	
	return true;
}

