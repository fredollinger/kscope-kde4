#ifndef Q_LIST_VIEW_ITEM4_H
#define Q_LIST_VIEW_ITEM4_H

#include <QObject>
#include <QListView>

namespace kscope4{
class QListViewItem4 : public QObject
{
public: 
	QListViewItem4();
    	QListViewItem4( QListView * parent );
    	QListViewItem4( QListViewItem4 * parent );
    	QListViewItem4( QListView * parent, QListViewItem4 * after );
    	QListViewItem4( QListViewItem4 * parent, QListViewItem4 * after );
	virtual ~QListViewItem4();
};

} //namespace kscope4
#endif
