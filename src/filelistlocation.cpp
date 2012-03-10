#include "filelistlocation.h"
#include <QList>

namespace kscope4{
FileListLocation::FileListLocation() : QWidget()
{
}

FileListLocation::~FileListLocation() 
{
}

void FileListLocation::append(QString sPath, uint nLine, uint nCol){
	m_sPathList.append(sPath);
	m_nLineList.append(nLine);
	m_nColList.append(nCol);
	return;
}

} // namespace kscope4
// Fri Mar  9 21:34:15 PST 2012
