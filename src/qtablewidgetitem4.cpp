#include <QStringList>
#include <QAbstractTableModel>
#include <QString>
#include <QListWidgetItem>
#include <qdebug.h>
#include "qlistviewitem4.h"

namespace kscope4{

QListViewItem4::QListViewItem4(QListView * parent) 
{
	qDebug() <<"QListViewItem4::QListViewItem4() FIXME\n";
}

QListViewItem4::QListViewItem4(QListViewItem4 *f, QListViewItem4 *l){
}

QListViewItem4::QListViewItem4(QListView *v, QListViewItem4 *l){
}

/*
int QListViewItem4::compare(QListViewItem4 *i, int col, bool){
	qDebug() <<"QListViewItem4::compare() FIXME\n";
	return 0;
} 
*/

/*
QListViewItem4::QListViewItem4( QListView *parent, QListViewItem4 *after) : QStringList()
{
	qDebug() <<"QListViewItem4::QListViewItem4() FIXME\n";
}

QListViewItem4::QListViewItem4( QListViewItem4 *parent, QListViewItem4 *after) : QStringList()
{
	qDebug() <<"QListViewItem4::QListViewItem4() FIXME\n";
}
*/

/**
 */
QListViewItem4::~QListViewItem4()
{
	// close();
}

} // namespace kscope4

// Sun Sep  4 12:23:20 PDT 2011
