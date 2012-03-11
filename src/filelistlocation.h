#ifndef FILE_LIST_LOCATION_H
#define FILE_LIST_LOCATION_H

#include <QList>
#include <QWidget>

namespace kscope4{
class FileListLocation : public QWidget
{

Q_OBJECT

public:
	FileListLocation();
	~FileListLocation();
	void append(QString, uint, uint);
	void flListFromStringList(const QStringList&, FileListLocation&);
	void stringListFromFlList(QStringList&, const FileListLocation&);

private:
	QList<QString> m_sPathList;
	QList<uint> m_nLineList;
	QList<uint> m_nColList;
};

}
#endif // FILE_LIST_LOCATION_H
