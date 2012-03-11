#ifndef SESSION_H
#define SESSION_H

#include <QList>
#include <QWidget>

namespace kscope4{
class Session : public QWidget
{

Q_OBJECT

public:
	Session();
	~Session();

private:
	QList<QString> m_sPathList;
	QList<uint> m_nLineList;
	QList<uint> m_nColList;

};

}
#endif // SESSION_H
