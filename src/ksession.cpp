#include "ksession.h"
#include <QList>
#include <QDebug>

namespace kscope4{
KSession::KSession() : QWidget()
{
}

KSession::~KSession() 
{
}

void KSession::stringList(QStringList& sl)
{
	#if 0
	FileLocationList* pList;
	QString sLoc;

	// Nasty...
	pList = (FileLocationList*)&fll;
	sl.clear();
	
	// Turn the object list into a string list, so that it can be written in
	// the configuration file
	// QListIterator<QList<kscope4::FileLocation*>*> pLoc;


	// /home/follinge/projects/kscope-kde4/src/project4.cpp :47:2: error: 'pLoc' is not a member of 'QListIterator<QList<kscope4::FileLocation*>*>'
	// /home/follinge/projects/kscope-kde4/src/project4.cpp:44:2: error: 'pLoc' is not a member of 'QListIterator<QList<kscope4::FileLocation*>*>'
	FileLocation* pLoc;
	QListIterator<FileLocationList*>::pLoc(FileLocation);

	// for (pLoc = pList->first(); pLoc != NULL; pLoc = pList->next()) {
 	//for (pLoc = pList->begin(); pLoc != pList->end(); ++pLoc){
	//	sLoc = "";
		// QTextOStream(&sLoc) << pLoc->m_sPath << ":" << pLoc->m_nLine << ":" 
				//<< pLoc->m_nCol;

		QTextStream(&sLoc, QIODevice::WriteOnly) << *pLoc.m_sPath << ":" 
			<< *pLoc.m_nLine << ":" << *pLoc.m_nCol;
		sl.append(sLoc);
	}
	#endif
}
} // namespace kscope4
// Sat Mar 10 19:22:41 PST 2012
