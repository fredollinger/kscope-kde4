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

void KSession::toStringList(QStringList& sl) const
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

void KSession::FromStringList(const QStringList& sl)
{
	#if 0
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
	#endif
}
} // namespace kscope4
// Sat Mar 10 19:22:41 PST 2012
