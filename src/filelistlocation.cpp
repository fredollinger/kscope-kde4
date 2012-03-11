#include "filelistlocation.h"
#include <QList>
#include <QDebug>
#include <QTextStream>

namespace kscope4{
FileListLocation::FileListLocation() : QWidget()
{
}

FileListLocation::~FileListLocation() 
{
}

void 
FileListLocation::append(QString sPath, uint nLine, uint nCol){
	m_sPathList.append(sPath);
	m_nLineList.append(nLine);
	m_nColList.append(nCol);
	return;
}

void
FileListLocation::flListFromStringList(const QStringList& sl, FileListLocation &fll)
{
	QStringList::ConstIterator itr;
	QString sPath;
	uint nLine, nCol;

	qDebug() << __PRETTY_FUNCTION__ << "FIXME";

	#if 0
	// Transform the string into a list of file locations
	for (itr = sl.begin(); itr != sl.end(); ++itr) {
		sPath = (*itr).section(':', 0, 0);
		nLine = (*itr).section(':', 1, 1).toUInt();
		nCol = (*itr).section(':', 2, 2).toUInt();
		fll.append(new FileLocation(sPath, nLine, nCol));
	}
	#endif
}

// BEGIN string List From FlList
void FileListLocation::stringListFromFlList(QStringList& sl){
	qDebug() << __PRETTY_FUNCTION__ << "FIXME";

//	FileLocationList* pList;
//	FileLocation* pLoc;
	QString sLoc;

	sl.clear();

//	QList<QString> m_sPathList;

	int c=0;
	
	QListIterator<QString> i(m_sPathList);
    	while (i.hasNext()){
		qDebug() << "FIXME: do it here.";	
		sLoc = "";

		QTextStream(&sLoc, QIODevice::WriteOnly) << i << ":" << 
			m_nLineList.at(c) << 
			":" << m_nColList.at(c);

		sl.append(sLoc);

		// last line here c++
		c++;
	}

	// Turn the object list into a string list, so that it can be written in
	// the configuration file
	/*
	for (pLoc = pList->first(); pLoc != NULL; pLoc = pList->next()) {
		sLoc = "";
		QTextOStream(&sLoc) << pLoc->m_sPath << ":" << pLoc->m_nLine << ":" 
				<< pLoc->m_nCol;
		sl.append(sLoc);
	}
	*/
}
// END string List From FlList

} // namespace kscope4
// Fri Mar  9 21:34:15 PST 2012
