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

#include <QRegExp>
#include <qregexp.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <kurlrequester.h>
#include <klineedit.h>
#include <kmessagebox.h>
#include <klocale.h>
#include "newprojectdlg4.h"
#include "autocompletionlayout4.h"

/**
 * Class constructor.
 * @param	bNewProj	true to create a new project dialog, false to display
 *						the properties of an existing project
 * @param	pParent		The parent widget
 * @param	szName		The widget's name
 */
NewProjectDlg::NewProjectDlg(bool bNewProj, QWidget* pParent, 
	const char* szName) :
	m_bNewProj(bNewProj)
{
	ProjectBase::Options opt;
}

NewProjectDlg::~NewProjectDlg()
{
}

/**
 * Class constructor.
 * @param	pParent		The parent widget
 * @param	szName		The widget's name
 */
AutoCompletionDlg::AutoCompletionDlg(QWidget* pParent,
	const char* szName ) 
{
}

/**
 * Class destructor.
 */
AutoCompletionDlg::~AutoCompletionDlg()
{
}


/**
 * Fills a structure with all user-configured project options.
 * @param	opt	The structure to fill
 */
void NewProjectDlg::getOptions(ProjectBase::Options& opt)
{
	/*
	opt.sSrcRootPath = m_pSrcRootRequester->url();
	opt.slFileTypes = m_slTypes;
	opt.bKernel = m_pKernelCheck->isChecked();
	opt.bInvIndex = m_pInvCheck->isChecked();
	opt.bNoCompress = m_pNoCompCheck->isChecked();
	opt.bSlowPathDef = m_pSlowPathCheck->isChecked();
		
	if (m_pAutoRebuildCheck->isChecked())
		opt.nAutoRebuildTime = m_pAutoRebuildSpin->value();
	else
		opt.nAutoRebuildTime = -1;
		
	if (m_pTabWidthCheck->isChecked())
		opt.nTabWidth = m_pTabWidthSpin->value();
	else
		opt.nTabWidth = 0;
		
	opt.bACEnabled = m_pACCheck->isChecked();
	opt.nACMinChars = m_pAutoCompDlg->m_nMinChars;
	opt.nACDelay = m_pAutoCompDlg->m_nDelay;
	opt.nACMaxEntries = m_pAutoCompDlg->m_nMaxEntries;
	
	opt.sCtagsCmd = m_pCtagsCmdEdit->text();
	*/
}

/**
 * Retrieves the text entered by the user in the dialog's "Project Name" edit
 * box.
 * @return	The name of the new project
 */
/*
QString NewProjectDlg::getName()
{
	return m_pNameEdit->text();
}
*/

/**
 * Retrieves the text entered by the user in the dialog's "Project Path" edit
 * box.
 * Note that the chosen path will be the parent of the new project's
 * directory, created under it using the project's name.
 * @return	The full path of the parent directory for the new project
 */
/*
QString NewProjectDlg::getPath()
{
	if (m_pHiddenDirCheck->isChecked())
		return QString(m_pSrcRootRequester->url()) + "/.cscope";
	
	return m_pPathRequester->url();
}
*/

// Sun Jun 19 18:51:52 UTC 2011
