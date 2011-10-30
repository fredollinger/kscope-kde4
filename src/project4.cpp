#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <kconfiggroup.h>
#include <klocale.h>
#include <kmessagebox.h>

#include <QTextStream>

#include "project4.h"
#include "kscopeconfig4.h"
#include "cscopefrontend4.h"

#define PROJECT_CONFIG_VER 4

inline void flListFromStringList(FileLocationList& fll, const QStringList& sl)
{
	QStringList::ConstIterator itr;
	QString sPath;
	uint nLine, nCol;

	// Transform the string into a list of file locations
	for (itr = sl.begin(); itr != sl.end(); ++itr) {
		sPath = (*itr).section(':', 0, 0);
		nLine = (*itr).section(':', 1, 1).toUInt();
		nCol = (*itr).section(':', 2, 2).toUInt();
		fll.append(new FileLocation(sPath, nLine, nCol));
	}
}

inline void stringListFromFlList(QStringList& sl, const FileLocationList& fll)
{
	FileLocationList* pList;
	FileLocation* pLoc;
	QString sLoc;

	// Nasty...
	pList = (FileLocationList*)&fll;
	sl.clear();
	
	// Turn the object list into a string list, so that it can be written in
	// the configuration file
	for (pLoc = pList->first(); pLoc != NULL; pLoc = pList->next()) {
		sLoc = "";
		// QTextOStream(&sLoc) << pLoc->m_sPath << ":" << pLoc->m_nLine << ":" 
				// << pLoc->m_nCol;

		QTextStream(&sLoc, QIODevice::WriteOnly) << pLoc->m_sPath << ":" 
			<< pLoc->m_nLine << ":" << pLoc->m_nCol;

		sl.append(sLoc);
	}
}
/**
 */
Project::Project() : ProjectBase(),
	m_pConf(NULL)
{
}

/**
 */
Project::~Project()
{
	close();
}

bool Project::open(const QString& sPath)
{
	QString sConfFile;
	Options opt;
	
	// Associate the object with the project directory
	m_dir.setPath(sPath);
	if (!m_dir.exists()) {
		KMessageBox::error(0, i18n("Project directory does not exist"));
		return false;
	}
	
	// Initialise the file-list file object
	m_fiFileList.setFileName(sPath + "/cscope.files");

	// Open the configuration files
	m_pConf = new KConfig(sPath + "/cscope.proj");

	// Verify the configuration file's version is compatible
	// ORIG: m_pConf->setGroup("");
	KConfigGroup gp(m_pConf, "");

	// ORIG: if (m_pConf->readUnsignedNumEntry("Version", 0) != PROJECT_CONFIG_VER) {
	if ( (unsigned int) gp.readEntry("Version", 0) != PROJECT_CONFIG_VER) {
		KMessageBox::error(0, i18n("Your project is not compatible with this "
				"version of KScope.\nPlease re-create the project."));
		return false;
	}
	
	// Get the project name
	// ORIG: m_pConf->setGroup("Project");
	KConfigGroup pGp(m_pConf, "Project");
	m_sName = pGp.readEntry("Name");
	if (m_sName == QString::null) {
		KMessageBox::error(0, i18n("Cannot read project name"));
		return false;
	}
	
	// Get stored options
	initOptions();
	
	// Set default make values for new projects (overriden in loadSession(), 
	// which is not called for new projects)
	m_sMakeRoot = getSourceRoot();
	m_sMakeCmd = "make";
	
	return true;
}

/**
 */
void Project::close()
{
	if (m_pConf)
		delete m_pConf;

	m_fiFileList.close();
}

/**
 * Returns a semi-colon separated list of the file types included in the
 * current project.
 */
QString Project::getFileTypes() const
{
	QString sTypes;

	// ORIG: m_pConf->setGroup("Project");
	KConfigGroup gp(m_pConf, "Project");

	// ORIG: return m_pConf->readEntry("FileTypes");
	return gp.readEntry("FileTypes");
}

/**
 * Reads the project's options from the configuration file.
 * @param	opt	A structure to fill with the read options
 */
void Project::getOptions(Options& opt) const
{
	// Get project properties
	// ORIG: m_pConf->setGroup("Project");
	KConfigGroup gp(m_pConf, "Project");

	opt.sSrcRootPath = gp.readEntry("RootPath", "/");
	opt.slFileTypes = gp.readListEntry("FileTypes", ' ');
	opt.bKernel = gp.readBoolEntry("Kernel", DEF_IS_KERNEL);
	opt.bInvIndex = gp.readBoolEntry("InvIndex", DEF_INV_INDEX);
	opt.bNoCompress = gp.readBoolEntry("NoCompress", DEF_NO_COMPRESS);
	opt.bSlowPathDef = gp.readBoolEntry("SlowPathDef", DEF_SLOW_PATH);
	opt.nAutoRebuildTime = gp.readNumEntry("AutoRebuildTime");
	opt.nTabWidth = gp.readUnsignedNumEntry("TabWidth");
	opt.sCtagsCmd = gp.readEntry("CtagsCommand", DEF_CTAGS_COMMAND);
			
	// Get auto-completion options
	// ORIG: m_pConf->setGroup("AutoCompletion");
	KConfigGroup pAC(m_pConf, "Project");

	opt.bACEnabled = pAc.readBoolEntry("Enabled");
	opt.nACMinChars = pAc.readUnsignedNumEntry("MinChars",
			DEF_AC_MIN_CHARS);
	opt.nACDelay = pAc.readUnsignedNumEntry("Delay", DEF_AC_DELAY);
	opt.nACMaxEntries = pAc.readUnsignedNumEntry("MaxEntries",
			DEF_AC_MAX_ENTRIES);
}

/**
 * Sets project options.
 * @param	opt	A structure containing the new parameters to set
 */
void Project::setOptions(const Options& opt)
{
	// Write the options to the configuration nfile
	writeOptions(m_pConf, opt);
				
	// Update project parameters
	initOptions();
}

/**
 */
void Project::loadSession(Session& sess)
{
	QStringList slEntry;
	
	// ORIG: m_pConf->setGroup("Session");
	KConfigGroup pS(m_pConf, "Session");
	
	// Read the list of open file locations
	slEntry = pS.readListEntry("OpenFiles");
	flListFromStringList(sess.fllOpenFiles, slEntry);
	
	// Get the path of the last viewed file
	sess.sLastFile = pS.readEntry("LastOpenFile");
	
	// Read the lists of locked query files and call-tree/graph files
	sess.slQueryFiles = pS.readListEntry("QueryFiles");
	sess.slCallTreeFiles = pS.readListEntry("CallTreeFiles");
	
	// Read the list of bookmarks
	slEntry = pS.readListEntry("Bookmarks");
	flListFromStringList(sess.fllBookmarks, slEntry);
	
	// Read make-related information
	sess.sMakeCmd = pS.readEntry("MakeCommand", "make");
	sess.sMakeRoot = pS.readEntry("MakeRoot", getSourceRoot());
	
	// Cache make values
	m_sMakeCmd = sess.sMakeCmd;
	m_sMakeRoot = sess.sMakeRoot;
}

/**
 * Saves session-related information in the project's configuration file.
 * @param	sess	Session parameters
 */
void Project::storeSession(const Session& sess)
{
	QStringList slEntry;
	
	// ORIG: m_pConf->setGroup("Session");
	KConfigGroup pS(m_pConf, "Session");
	
	// Write the list of open file locations
	stringListFromFlList(slEntry, sess.fllOpenFiles);
	pS.writeEntry("OpenFiles", slEntry);
	
	// Write the path of the last viewed file
	pS.writeEntry("LastOpenFile", sess.sLastFile);
	
	// Write the lists of locked query files and call-tree/graph files
	pS.writeEntry("QueryFiles", sess.slQueryFiles);
	pS.writeEntry("CallTreeFiles", sess.slCallTreeFiles);
	
	// Write the list of bookmarks
	stringListFromFlList(slEntry, sess.fllBookmarks);
	pS.writeEntry("Bookmarks", slEntry);
	
	// Write make-related information
	// Be careful not to write empty strings, as they may occur if the make
	// dialogue was not invoked during this session
	if (!sess.sMakeCmd.isEmpty())
		pS.writeEntry("MakeCommand", sess.sMakeCmd);
	if (!sess.sMakeRoot.isEmpty())
		pS.writeEntry("MakeRoot", sess.sMakeRoot);
}

/**
 * Fills a list object with all files in the project.
 * List items are created by reading and parsing all file name entries from
 * the project's 'cscope.files' file.
 * Note that the file may contain option lines, beginning with a dash. These
 * should be ignored.
 * @param	pList	Pointer to the object to fill
 */
bool Project::loadFileList(FileListTarget* pList)
{
	QString sFilePath;
	
	// Open the 'cscope.files' file
	if (!m_fiFileList.open(IO_ReadOnly))
		return false;

	// Read all file names from the file
	QTextStream str(&m_fiFileList);
	while ((sFilePath = str.readLine()) != QString::null) {
		// Skip option lines
		if (sFilePath.at(0) == '-')
			continue;

		// Set the new list item
		pList->addItem(sFilePath);
	}

	m_fiFileList.close();
	return true;
}

/**
 * Writes all file entries in a list view widget to the project's
 * 'cscope.files' file (replacing current file contents.)
 * @param	pList	Pointer to the object from which to take the new entries
 */
bool Project::storeFileList(FileListSource* pList)
{
	QString sFilePath;
	
	// Open the 'cscope.files' file
	if (!m_fiFileList.open(IO_WriteOnly | IO_Truncate))
		return false;

	QTextStream str(&m_fiFileList);

	// Write all file names
	if (pList->firstItem(sFilePath)) {
		do {
			str << sFilePath << "\n";
		} while (pList->nextItem(sFilePath));
	}

	m_fiFileList.close();
	return true;
}

/**
 * Adds a single file to the file list.
 * @param	sPath	The path of the file to add
 * @return	true if successful, false otherwise
 */
bool Project::addFile(const QString& sPath)
{
	// Open the 'cscope.files' file
	if (!m_fiFileList.open(IO_WriteOnly | IO_Append))
		return false;
	
	// Write the file path
	QTextStream str(&m_fiFileList);
	str << sPath << "\n";

	m_fiFileList.close();
	return true;	
}

/**
 * Determines whether the project includes any files.
 * Reads the 'cscope.files' file and looks for any file names in it. If none
 * is present, then the project is considered empty.
 * Note that the file may contain option lines, beginning with a dash. These
 * should be ignored.
 * @return	true if no files are included in the project, false otherwise
 */
bool Project::isEmpty()
{
	QString sPath, sFileName;
	bool bResult = true;
	
	// Open the 'cscope.files' file
	if (!m_fiFileList.open(IO_ReadOnly))
		return true;

	// Find at least one file name entry in the file
	QTextStream str(&m_fiFileList);
	while ((sPath = str.readLine()) != QString::null) {
		if (sPath.at(0) != '-') {
			bResult = false;
			break;
		}
	}

	m_fiFileList.close();
	return bResult;
}

/**
 * Copies the list of previously queried symbols to the target object.
 * @param	slSymHistory	The list object to copy into
 */
void Project::getSymHistory(QStringList& slSymHistory) const
{
	slSymHistory = m_slSymHistory;
}

/**
 * Copies the list of previously queried symbols from the target object.
 * @param	slSymHistory	The list object to copy from
 */
void Project::setSymHistory(QStringList& slSymHistory)
{
	m_slSymHistory = slSymHistory;
}

void Project::getMakeParams(QString& sCmd, QString& sDir) const
{
	sCmd = m_sMakeCmd;
	sDir = m_sMakeRoot;
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
	conf.setGroup("");
	conf.writeEntry("Version", PROJECT_CONFIG_VER);
	
	// Write project properties in the configuration file
	conf.setGroup("Project");
	conf.writeEntry("Name", sName);
	writeOptions(&conf, opt);
	
	// Flush the config file data, so the project is created even if KScope
	// crashes...
	conf.sync();

	return true;
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
	// ORIG: pConf->setGroup("AutoCompletion");
	KConfigGroup ac(pConf, "AutoCompletion");
	ac.writeEntry("Enabled", opt.bACEnabled);
	ac.writeEntry("MinChars", opt.nACMinChars);
	ac.writeEntry("Delay", opt.nACDelay);
	ac.writeEntry("MaxEntries", opt.nACMaxEntries);
	return;
}

// Sat Oct 29 13:45:28 PDT 2011
