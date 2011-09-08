#ifndef KPROGRESS4_H
#define KPROGRESS4_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QString>

namespace kscope4{
class QListViewItem : public QAbstractTableModel
{
	Q_OBJECT
public:
	// QListViewItem(QListView*, QListViewItem*);
	// QListViewItem(QListViewItem*, QListViewItem*);
	QListViewItem();
	QString* text(int); // return a string at the given position
	virtual ~QListViewItem();
private:
};

}
#endif // KPROGRESS4_H
