#ifndef QLISTVIEW4_H
#define QLISTVIEW4_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QString>
#include <QWidget>
#include <QListWidgetItem>

namespace kscope4{
class QListView : QObject
{
	Q_OBJECT
public:
	QListView();
	QString* text(int); // return a string at the given position
	virtual ~QListView();
private:
};

}
#endif 

// Thu Sep 15 19:54:15 PDT 2011
