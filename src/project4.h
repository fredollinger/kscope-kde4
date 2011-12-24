#ifndef PROJECT_H
#define PROJECT_H

#include "ksconfig4.h"
#include "projectbase4.h"

/**
 * @author Elad Lahav
 */
namespace kscope4{
class Project : public ProjectBase
{
public:
	Project();
	virtual ~Project();
	
	struct Session {
		FileLocationList fllOpenFiles;
		QString sLastFile;
		QStringList slQueryFiles;
		QStringList slCallTreeFiles;
		FileLocationList fllBookmarks;
		QString sMakeCmd;
		QString sMakeRoot;
	};
	virtual bool open(const QString&);
	virtual bool loadFileList(FileListTarget*);
	virtual bool storeFileList(FileListSource*);
	virtual bool addFile(const QString&);
	virtual bool isEmpty();
	virtual void close();
	
	virtual QString getFileTypes() const;
	virtual void getOptions(Options&) const;
	virtual void setOptions(const Options&);
	virtual void loadSession(Session&);
	virtual void storeSession(const Session&);
	virtual void getSymHistory(QStringList&) const;
	virtual void setSymHistory(QStringList&);
	virtual void getMakeParams(QString&, QString&) const;

	/**
	 * Determines whether a project is based on a Cscope.out file, and is
	 * therefore considered as a temporary project.
	 * @return	true if this is a temporary project, false otherwise
	 */
	virtual bool isTemporary() { return false; }
	static bool create(const QString&, const QString&, const Options&);
	
private:
	/** The configuration file ("cscope.proj") */
	kscope4::KSConfig* m_pConf;

	/** The file that holds the paths of all source files in this project
	("cscope.files") */
	QFile m_fiFileList;
	
	QString m_sMakeCmd;
	
	QString m_sMakeRoot;
	
	static void writeOptions(kscope4::KSConfig*, const Options&);
};

#endif
}// namespace kscope4
// Sat Dec 24 13:15:13 PST 2011
