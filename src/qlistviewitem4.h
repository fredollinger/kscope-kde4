#ifndef KPROGRESS4_H
#define KPROGRESS4_H

#include <QTreeView>

namespace kscope4{
class QListViewItem : public QTreeView
{
public:
	QListViewItem(QListView*, QListViewItem*);
	QListViewItem(QListViewItem*, QListViewItem*);
	QListViewItem();
	~QListViewItem();
};

}
#endif // KPROGRESS4_H
