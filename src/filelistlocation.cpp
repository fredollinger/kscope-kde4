#include "filelistlocation.h"
#include <QList>

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

} // namespace kscope4
// Fri Mar  9 21:34:15 PST 2012
