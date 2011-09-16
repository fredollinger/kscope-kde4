#ifndef QLISTVIEWITEM4_H
#define QLISTVIEWITEM4_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QString>

#include "qlistview4.h"

namespace kscope4{
class QListViewItem : public QListWidgetItem
{
	Q_OBJECT
public:
	// QListViewItem(QListView*, QListViewItem*);
	// QListViewItem(QListViewItem*, QListViewItem*);
	QListViewItem(QListView * parent);
	QString* text(int); // return a string at the given position
	virtual ~QListViewItem();
private:
};

}
#endif 
