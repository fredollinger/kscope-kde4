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
FileListLocation::flListFromStringList(const QStringList& sl)
{
	QStringList::ConstIterator itr;
	QString sPath;
	uint nLine, nCol;

	qDebug() << __PRETTY_FUNCTION__ << "FIXME";

	// Transform the string into a list of file locations
	for (itr = sl.begin(); itr != sl.end(); ++itr) {
		sPath = (*itr).section(':', 0, 0);
		nLine = (*itr).section(':', 1, 1).toUInt();
		nCol = (*itr).section(':', 2, 2).toUInt();
		append(sPath, nLine, nCol);
	}
}

// BEGIN string List From FlList
void FileListLocation::stringListFromFlList(QStringList& sl){
	qDebug() << __PRETTY_FUNCTION__ << "FIXME";

	QString sLoc;
	QString qs;
	int c=0;

	sl.clear();
	
	QListIterator<QString> i(m_sPathList);
    	while (i.hasNext()){
		qDebug() << "FIXME: do it here.";	
		sLoc = "";

		qDebug() << "fix this";
		qs = i.next();
		sLoc = qs + ":" + m_nLineList.at(c) + ":" + m_nColList.at(c);

		sl.append(sLoc);

		// last line here c++
		c++;
	}
}
// END string List From FlList

} // namespace kscope4
// Fri Mar  9 21:34:15 PST 2012
