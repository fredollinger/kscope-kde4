#ifndef SESSION_H
#define SESSION_H

#include <QList>
#include <QWidget>
#include "filelistlocation.h"

namespace kscope4{
class Session : public QWidget
{

Q_OBJECT

public:
	Session();
	~Session();

private:
	FileListLocation fllOpenFiles;
	QString sLastFile;
	QStringList slQueryFiles;
	QStringList slCallTreeFiles;
	FileListLocation fllBookmarks;
	QString sMakeCmd;
	QString sMakeRoot;
};

}
#endif // SESSION_H
