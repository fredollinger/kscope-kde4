#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "projectbase4.h"
#include "qdebug.h"

/**
 * @author Elad Lahav
 */
class ProjectManager : public QObject
{
public: 
	ProjectManager();
	virtual ~ProjectManager();
	
	bool create(const QString&, const QString&, const kscope4::ProjectBase::Options&,
		QString&);
	bool open(const QString&);
	bool openCscopeOut(const QString&);
	void close();
	QString getProjName() const;
	QString getSourceRoot() const;
	
	kscope4::ProjectBase* curProject() const { 
		qDebug() << "ProjectBase* ProjectManger::curProject()";
		return m_pCurProj; 
	}
	
private:
	/** The current project (NULL if no project is open). */
	kscope4::ProjectBase* m_pCurProj;
};
#endif
// Thu Nov 24 14:50:51 PST 2011
