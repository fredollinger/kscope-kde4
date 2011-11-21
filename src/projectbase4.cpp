#include <QTextStream>
#include <Q3PtrList>
#include "projectbase4.h"
#include "kscopeconfig4.h"
#include "cscopefrontend4.h"
#include "kio4.h"

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
 	if (!fi.exists() || !isCscopeOut(fi.absoluteFilePath()))
		return false;
		
	// Set the project's directory
	m_dir = fi.dir();
	
	// Set the name of the project to be the full path of the file
 	m_sName = fi.absoluteFilePath();
	
	// Initialise project options (assume source root is the folder holding the
	// cscope.out file)
	getDefOptions(m_opt);
 	m_opt.sSrcRootPath = m_dir.absolutePath();
	
	return true;
}

/**
 * Determines if the cscope.out file for this project exists.
 * @return	true if the database exists, false otherwise
 */
bool ProjectBase::dbExists()
{
	return m_dir.exists("cscope.out");
}

void ProjectBase::getOptions(Options& opt) const
{
	getDefOptions(opt);
}

void ProjectBase::getMakeParams(QString& sCmd, QString& sDir) const
{
	sCmd = "make";
	sDir = getSourceRoot();
}

/**
 * Fills a structure with default properties for a new project.
 * Default properties are partly based on the system profile.
 * @param	opt	The structure to fill
 */
void ProjectBase::getDefOptions(Options& opt)
{
	// Set default source path to file-system root
	opt.sSrcRootPath = "/";
	
	// Initialise MIME-type list
	opt.slFileTypes.append("*.c");
	opt.slFileTypes.append("*.h");

	// Set other options
	opt.bKernel = DEF_IS_KERNEL;
	opt.bInvIndex = DEF_INV_INDEX;
	opt.bNoCompress = DEF_NO_COMPRESS;
	opt.bSlowPathDef = DEF_SLOW_PATH;
	opt.nACMinChars = DEF_AC_MIN_CHARS;
	opt.nACDelay = DEF_AC_DELAY;
	opt.nACMaxEntries = DEF_AC_MAX_ENTRIES;
	opt.nTabWidth = DEF_TAB_WIDTH;
	
	// Set profile-dependant options
	if (Config().getSysProfile() == KScopeConfig::Fast) {
		opt.nAutoRebuildTime = 10;
		opt.bACEnabled = true;
	}
	else {
		opt.nAutoRebuildTime = -1;
		opt.bACEnabled = false;
	}
}
	
void ProjectBase::initOptions()
{
	// Load the options
	getOptions(m_opt);

	// Create the argument list for invoking Cscope
	m_nArgs = 0;
	if (m_opt.bKernel)
		m_nArgs |= CscopeFrontend::Kernel;
	if (m_opt.bInvIndex)
		m_nArgs |= CscopeFrontend::InvIndex;
	if (m_opt.bNoCompress)
		m_nArgs |= CscopeFrontend::NoCompression;
	if (m_opt.bSlowPathDef)
		m_nArgs |= CscopeFrontend::SlowPathDef;
}

/**
 * Determines if the given file is a Cscope cross-reference database.
 * @param	sPath	The full path of the file to check
 * @return	true if the given file is a cscope.out file, false otherwise
 */
bool ProjectBase::isCscopeOut(const QString& sPath)
{
	QFile file(sPath);
	QString sLine;
	int nVer;
	char szDir[PATH_MAX];

	// Try to open the file
	if (!file.open(IO_ReadOnly))
		return false;
		
	// Check if the first line matches the expected format
	sLine = QTextStream(&file).readLine();
 	return sscanf(sLine.toLatin1(), "cscope %d %s", &nVer, szDir) == 2;
}

/**
 * Fills a list object with all files in the project.
 * List items are created by reading and parsing all file name entries from
 * the project's 'cscope.files' file.
 * Note that the file may contain option lines, beginning with a dash. These
 * should be ignored.
 * @param	pList	Pointer to the object to fill
 */
bool ProjectBase::loadFileList(FileListTarget* pList)
{
	QString sFilePath;
	QFile file;
	
	// Make sure the file exists
	if (!m_dir.exists("cscope.files"))
		return false;
	
	// Open the file
 	file.setFileName(m_dir.absolutePath() + "/cscope.files");
	if (!file.open(IO_ReadOnly))
		return false;

	// Read all file names from the file
	QTextStream str(&file);
	while ((sFilePath = str.readLine()) != QString::null) {
		// Skip option lines
		if (sFilePath.at(0) == '-')
			continue;

		// Set the new list item
		pList->addItem(sFilePath);
	}

	file.close();
	return true;
}
// Sun Nov 20 15:57:18 PST 2011
