#include <QStringList>
#include <QAbstractTableModel>
#include <QString>
#include <QListWidgetItem>
#include <qdebug.h>
#include "qtableviewitem4.h"
#include "qlistviewitem4.h"

namespace kscope4{

QTableViewItem4::QTableViewItem4(QTableView * parent) 
{
	qDebug() <<"QTableViewItem4::QListViewItem4() FIXME\n";
}

QTableViewItem4::QTableViewItem4(QTableViewItem4 *f, QTableViewItem4 *l){
}

QTableViewItem4::QTableViewItem4(QTableView *v, QTableViewItem4 *l){
}

/*
int QTableViewItem4::compare(QTableViewItem4 *i, int col, bool){
	qDebug() <<"QTableViewItem4::compare() FIXME\n";
	return 0;
} 
*/

/*
QTableViewItem4::QTableViewItem4( QTableView *parent, QTableViewItem4 *after) : QStringTable()
{
	qDebug() <<"QTableViewItem4::QTableViewItem4() FIXME\n";
}

QTableViewItem4::QTableViewItem4( QTableViewItem4 *parent, QTableViewItem4 *after) : QStringTable()
{
	qDebug() <<"QTableViewItem4::QTableViewItem4() FIXME\n";
}
*/

/**
 */
QTableViewItem4::~QTableViewItem4()
{
	// close();
}

} // namespace kscope4

// Sun Sep  4 12:23:20 PDT 2011
