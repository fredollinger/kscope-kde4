#ifndef QLISTVIEWITEM4_H
#define QLISTVIEWITEM4_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QString>
#include <QListWidgetItem>

#include "qlistview4.h"

namespace kscope4{
class QListViewItem : public QObject
{
	Q_OBJECT
public:
	// QListViewItem(QListView*, QListViewItem*);
	// QListViewItem(QListViewItem*, QListViewItem*);
	QListViewItem(QListView * parent);


    QListViewItem(QListView * parent, QListViewItem * after);
    QListViewItem(QListViewItem * parent, QListViewItem * after);

	QString* text(int); // return a string at the given position

	virtual ~QListViewItem();

    	int compare(QListViewItem *i, int col, bool);
private:
};

}
#endif 
