/*
 * kscopeconfig4.cpp
 *
 * This is THE entry point to GLOBAL configuration options in KScope4
 *
 */
#include <kconfig.h>
#include <kapplication.h>
#include <kglobalsettings.h>
#include <qdebug.h>

#include "kscopeconfig4.h"
#include "ksconfig4.h"
#include "KSGlobalConfig.h"

// NOTE:
// This configuration file entry controls whether the welcome dialogue is
// displayed. Normally it only needs to be shown once, but the entry's name
// can be changed across versions to force the display of new information.
#define SHOW_WELCOME_ENTRY "ShowWelcomeDlg"

/**
 * Stores the display name and the configuration file entry for a configurable
 * GUI element.
 * @author	Elad Lahav
 */
struct ElementInfo
{
	/** The display name of the element. */
	const char* szName;
	
	/** The configuration file entry. */
	const char* szEntry;
};

/**
 * A list of GUI elements for which the colour can be configured.
 */
const ElementInfo eiColors[] = {
	{ "File List (Foreground)", "FileListFore" },
	{ "File List (Background)", "FileListBack" },
	{ "Tag List (Foreground)", "TagListFore" },
	{ "Tag List (Background)", "TagListBack" },
	{ "Query Window (Foreground)", "QueryListFore" },
	{ "Query Window (Background)", "QueryListBack" },
	{ "Call Graph (Background)", "GraphBack" },
	{ "Call Graph (Nodes)", "GraphNode" },
	{ "Call Graph (Text)", "GraphText" },
	{ "Call Graph (Multi-Call Nodes)", "GraphMultiCall" } 
};

/**
 * A list of GUI elements for which the font can be configured.
 */
const ElementInfo eiFonts[] = {
	{ "File List", "FileList" },
	{ "Tag List", "TagList" },
	{ "Query Page", "QueryList" },
	{ "Call Graph", "Graph" }
};

#define COLOR_NAME(_i)	eiColors[_i].szName
#define COLOR_ENTRY(_i)	eiColors[_i].szEntry
#define FONT_NAME(_i)	eiFonts[_i].szName
#define FONT_ENTRY(_i)	eiFonts[_i].szEntry

namespace kscope4{
KScopeConfig::KScopeConfig() : KSGlobalConfig(),
m_bFontsChanged(false)
{
}

/**
 * Class destructor.
 */
KScopeConfig::~KScopeConfig()
{
}

/**
 * Reads KScope's parameters from the standard configuration file.
 */
void KScopeConfig::load()
{
}

/**
 * Sets default values to he configuration parameters (except for those where
 * a default value has no meaning, such as the recent projects list).
 */
void KScopeConfig::loadDefault()
{
}
 
/**
 * Writes KScope's parameters from the standard configuration file.
 */
void KScopeConfig::store()
{
	qDebug() << "KScopeConfig::store()";
	writeConfig();
}

/**
 * Determines if this is the first time KScope was launched by the current
 * user.
 * @return	true if this is the first time, false otherwise
 */
bool KScopeConfig::isFirstTime()
{
	/*
	KConfig* pConf = kapp->config();

	pConf->setGroup("General");
	return pConf->readBoolEntry("FirstTime", true);
	*/
	
	qDebug() << "KScopeConfig::isFirstTime() NOT implemented. \n";
	return true;
}

/**
 * Determines if the welcome dialogue should be displayed.
 * Note that while the dialogue is displayed on the first invocation of KScope,
 * it may be required on other occasions (e.g., to display important information
 * on a per-version basis) and thus it is separated from isFirstTime().
 * @return	true if the dialogue should be shown, false otherwise
 */
bool KScopeConfig::showWelcomeDlg()
{
	/*
	KConfig* pConf = kapp->config();

	pConf->setGroup("General");
	return pConf->readBoolEntry(SHOW_WELCOME_ENTRY, true);
	*/
	return true;
}

/**
 * @return	The full path of the Cscope executable
 */
const QString& KScopeConfig::getCscopePath() const
{
	return m_cp.sCscopePath;
}

/**
 * @param	sPath	The full path of the Cscope executable
 */
void KScopeConfig::setCscopePath(const QString& sPath)
{
	m_cp.sCscopePath = sPath;
}

/**
 * @return	The full path of the Ctags executable
 */
const QString& KScopeConfig::getCtagsPath() const
{
	return m_cp.sCtagsPath;
}

/**
 * @param	sPath	The full path of the Ctags executable
 */
void KScopeConfig::setCtagsPath(const QString& sPath)
{
	m_cp.sCtagsPath = sPath;
}

/**
 * @return	The full path of the Dot executable
 */
const QString& KScopeConfig::getDotPath() const
{
	return m_cp.sDotPath;
}

/**
 * @param	sPath	The full path of the Dot executable
 */
void KScopeConfig::setDotPath(const QString& sPath)
{
	m_cp.sDotPath = sPath;
}

/**
 * @return	A sorted list of recently used project paths.
 */
const QStringList& KScopeConfig::getRecentProjects() const
{
	return mRecentProjects;
}

/**
 * Removes the given project path from recently used projects list.
 * @param	sProjPath	The path of the project to remove
 */
void KScopeConfig::removeRecentProject(const QString& sProjPath)
{

	qDebug() << "KScopeConfig::removeRecentProject need replacement to QString.find() \n";
	// mRecentProjects.remove(sProjPath);
}

/**
 * @return	true if the tag list should be visible, false otherwise
 */
bool KScopeConfig::getShowTagList() const
{
	return m_cp.bShowTagList;
}

/**
 * @param	bShowTagList	true to make the tag list visible, false otherwise
 */
void KScopeConfig::setShowTagList(bool bShowTagList)
{
	m_cp.bShowTagList = bShowTagList;
}

/**
 * Finds a colour to use for a GUI element.
 * @param	ce		Identifies the GUI element
 * @return	A reference to the colour object to use
 */
const QColor& KScopeConfig::getColor(ColorElement ce) const
{
	return m_cp.clrs[ce];
}

/**
 * Returns the display name of a GUI element whose colour can be configured.
 * @param	ce	The GUI element
 * @return	A name used in the colour configuration page
 */
QString KScopeConfig::getColorName(ColorElement ce) const
{
	return COLOR_NAME(ce);
}

/**
 * Sets a new colour to a GUI element.
 * @param	ce		Identifies the GUI element
 * @param	clr		The colour to use
 */ 
void KScopeConfig::setColor(ColorElement ce, const QColor& clr)
{
	m_cp.clrs[ce] = clr;
}

/**
 * Returns the display name of a GUI element whose font can be configured.
 * @param	ce	The GUI element
 * @return	A name used in the font configuration page
 */
QString KScopeConfig::getFontName(FontElement ce) const
{
	return FONT_NAME(ce);
}

/**
 * Sets a new font to a GUI element.
 * @param	fe		Identifies the GUI element
 * @param	font	The font to use
 */ 
void KScopeConfig::setFont(FontElement fe, const QFont& font)
{
	qDebug() << "KScopeConfig::setFont not implemented! \n";
	/*
	m_bFontsChanged = true;
	m_cp.fonts[fe] = font;
	*/
}

/**
 * @return	The column and direction by which the tags should be sorted
 */
KScopeConfig::CtagSort KScopeConfig::getCtagSortOrder()
{
	return m_cp.ctagSortOrder;
}

/**
 * @param	ctagSortOrder	The column and direction by which the tags should
 *							be sorted
 */
void KScopeConfig::setCtagSortOrder(CtagSort ctagSortOrder)
{
	m_cp.ctagSortOrder = ctagSortOrder;
}

/**
 * @return	true to work in Read-Only mode, false otherwise
 */
bool KScopeConfig::getReadOnlyMode()
{
	return m_cp.bReadOnlyMode;
}

/**
 * @param	bReadOnlyMode	true to work in Read-Only mode, false otherwise
 */
void KScopeConfig::setReadOnlyMode(bool bReadOnlyMode)
{
	m_cp.bReadOnlyMode = bReadOnlyMode;
}

/**
 * @return	true to load the last project on start-up, false otherwise
 */
bool KScopeConfig::getLoadLastProj()
{
	return m_cp.bLoadLastProj;
}

/**
 * @param	bLoadLastProj	true to load the last project on start-up, false
 *							otherwise
 */
void KScopeConfig::setLoadLastProj(bool bLoadLastProj)
{
	m_cp.bLoadLastProj = bLoadLastProj;
}

/**
 * @return	true to enable tag highlighting based on cursor position, false
 *			to disable this feature
 */
bool KScopeConfig::getAutoTagHl()
{
	return m_cp.bAutoTagHl;
}

/**
 * @param	bAutoTagHl	true to enable tag highlighting based on cursor
 *			position, false to disable this feature
 */
void KScopeConfig::setAutoTagHl(bool bAutoTagHl)
{
	m_cp.bAutoTagHl = bAutoTagHl;
}

/**
 * @return	true to use the short version of the query captions, false to use
 *			the long version
 */
bool KScopeConfig::getUseBriefQueryCaptions()
{
	return m_cp.bBriefQueryCaptions;
}

/**
 * @param	bBrief	true to use the short version of the query captions, false
 *			to use the long version
 */
void KScopeConfig::setUseBriefQueryCaptions(bool bBrief)
{
	m_cp.bBriefQueryCaptions = bBrief;
}

/**
 * @return	true to warn user when file is modified on disk, false
 *			otherwise
 */
bool KScopeConfig::getWarnModifiedOnDisk()
{
	return m_cp.bWarnModifiedOnDisk;
}

/**
 * @param	bWarn	true to warn user when file is modified on disk,
 *					false otherwise
 */
void KScopeConfig::setWarnModifiedOnDisk(bool bWarn)
{
	m_cp.bWarnModifiedOnDisk = bWarn;
}

/**
 * @return	true to sort files when a project is loaded, false otherwise
 */
bool KScopeConfig::getAutoSortFiles()
{
	return m_cp.bAutoSortFiles;
}

/**
 * @param	bSort	true to sort files when a project is loaded, false 
 *					otherwise
 */
void KScopeConfig::setAutoSortFiles(bool bSort)
{
	m_cp.bAutoSortFiles = bSort;
}

/**
 * @return	A command line for launching an external editor
 */
const QString& KScopeConfig::getExtEditor()
{
	return m_cp.sExtEditor;
}

/**
 * @param	sExtEditor	A command line for launching an external editor
 */
void KScopeConfig::setExtEditor(const QString& sExtEditor)
{
	m_cp.sExtEditor = sExtEditor;
}

/**
 * Determines if an external editor should be used.
 * An external editor is used if KScope is in Read-Only mode, and a command-
 * line for the editor was specified.
 * @return	true to use an external editor, false otherwise
 */
bool KScopeConfig::useExtEditor()
{
	return !m_cp.sExtEditor.isEmpty();
}

/**
 * @return	The chosen profile for this system (@see SysProfile)
 */
KScopeConfig::SysProfile KScopeConfig::getSysProfile() const
{
	return m_cp.profile;
}

/**
 * @param	profile	The system profile to use (@see SysProfile)
 */
void KScopeConfig::setSysProfile(KScopeConfig::SysProfile profile)
{
	m_cp.profile = profile;
}

/**
 * @return	The chosen popup menu type for the embedded editor (@see
 *			EditorPopup)
 */
KScopeConfig::EditorPopup KScopeConfig::getEditorPopup() const
{
	return m_cp.popup;
}

/**
 * @return	The name of the popup menu to use in the embedded editor
 */
QString KScopeConfig::getEditorPopupName() const
{
	switch (m_cp.popup) {
	case Embedded:
		return "ktexteditor_popup";
		
	case KScopeOnly:
		return "kscope_popup";
	}
	
	// Will not happen, but the compiler complains if no return statement is
	// given here
	return "";
}

/**
 * @param	popup	The popup menu to use for the embedded editor (@see
 *					EditorPopup)
 */
void KScopeConfig::setEditorPopup(KScopeConfig::EditorPopup popup)
{
	m_cp.popup = popup;
}

/**
 * @return	The default orientation for call graphs
 */
QString KScopeConfig::getGraphOrientation() const
{
	return m_cp.sGraphOrient;
}

/**
 * @param	sOrient	The default orientation for call graphs
 */
void KScopeConfig::setGraphOrientation(const QString& sOrient)
{
	m_cp.sGraphOrient = sOrient;
}

/**
 * @return	The maximal number of calls per graph node
 */
int KScopeConfig::getGraphMaxNodeDegree() const
{
	return m_cp.nGraphMaxNodeDegree;
}

/**
 * @param	nMaxNodeDegree	The maximal number of calls per graph node
 */
void KScopeConfig::setGraphMaxNodeDegree(int nMaxNodeDegree)
{
	m_cp.nGraphMaxNodeDegree = nMaxNodeDegree;
}

/**
 * @return	The default view in the call graph dialogue
 */
int KScopeConfig::getDefGraphView() const
{
	return m_cp.nDefGraphView;
}

/**
 * @param	nDefGraphView	The default view in the call graph dialogue
 */
void KScopeConfig::setDefGraphView(int nDefGraphView)
{
	m_cp.nDefGraphView = nDefGraphView;
}

/**
 * Returns a reference to a global configuration object.
 * The static object defined is this function should be the only KSCopeConfig
 * object in this programme. Any code that wishes to get or set global
 * configuration parameters, should call Config(), instead of defining its
 * own object.
 * @return	Reference to a statically allocated configuration object
 */
KScopeConfig& Config()
{
	static KScopeConfig conf;
	return conf;
}

/**
 * Adds the given project path to the beginning of the recently used projects
 * list.
 * @param	sProjPath	The path of the project to add
 */
void KScopeConfig::addRecentProject(const QString& sProjPath)
{
// FIXME: Change all m_slRecentProcject to mRecentProjects. 
	mRecentProjects.prepend(sProjPath);
	mRecentProjects.removeDuplicates();

}

/* Set the name of the project that we will load when start up KScope */
void KScopeConfig::setCurrentProject(const QString& sProjPath)
{ 
	qDebug() << "KScopeConfig::setCurrentProject(): "<< sProjPath;
	mLastOpenProject = sProjPath;
}

/* Set the name of the project that we will load when start up KScope */

const QString& KScopeConfig::getCurrentProject()
{

	return mLastOpenProject;

}

} // namespace kscope4
// Sun Dec 25 16:28:52 PST 2011
