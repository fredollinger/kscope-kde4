#ifndef Q_TABLE_VIEW_ITEM4_H
#define Q_TABLE_VIEW_ITEM4_H

#include <QObject>
#include <QTableView>

namespace kscope4{
class QTableViewItem4 : public QObject
{
public: 
	QTableViewItem4();
    	QTableViewItem4( QTableView * parent );
    	QTableViewItem4( QTableViewItem4 * parent );
    	QTableViewItem4( QTableView * parent, QTableViewItem4 * after );
    	QTableViewItem4( QTableViewItem4 * parent, QTableViewItem4 * after );
	virtual ~QTableViewItem4();
};

} //namespace kscope4
#endif
