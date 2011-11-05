#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "projectbase4.h"

/**
 * @author Elad Lahav
 */
class ProjectManager : public QObject
{
public: 
	ProjectManager();
	virtual ~ProjectManager();
	
	bool create(const QString&, const QString&, const ProjectBase::Options&,
		QString&);
	bool open(const QString&);
	bool openCscopeOut(const QString&);
	void close();
	QString getProjName() const;
	
	ProjectBase* curProject() const { return m_pCurProj; }
	
private:
	/** The current project (NULL if no project is open). */
	ProjectBase* m_pCurProj;
};

#endif
