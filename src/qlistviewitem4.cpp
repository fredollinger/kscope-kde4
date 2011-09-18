#include <QStringList>
#include <QAbstractTableModel>
#include <QString>
#include <QListWidgetItem>
#include <qdebug.h>
#include "qlistviewitem4.h"

namespace kscope4{

///home/follinge/projects/kscope-kde4/src/build/../queryview4.h :28:68: error: no matching function for call to ‘kscope4::QListViewItem::QListViewItem(QListView*&, kscope4::QListViewItem*&)’
QListViewItem::QListViewItem(QListView * parent) 
{
	qDebug() <<"QListViewItem::QListViewItem() FIXME\n";
}

QListViewItem::QListViewItem(QListViewItem *f, QListViewItem *l){
}

QListViewItem::QListViewItem(QListView *v, QListViewItem *l){
}

int QListViewItem::compare(QListViewItem *i, int col, bool){
	qDebug() <<"QListViewItem::compare() FIXME\n";
	return 0;
} 

/*
QListViewItem::QListViewItem( QListView *parent, QListViewItem *after) : QStringList()
{
	qDebug() <<"QListViewItem::QListViewItem() FIXME\n";
}

QListViewItem::QListViewItem( QListViewItem *parent, QListViewItem *after) : QStringList()
{
	qDebug() <<"QListViewItem::QListViewItem() FIXME\n";
}
*/

/**
 */
QListViewItem::~QListViewItem()
{
	// close();
}

} // namespace kscope4

// Sun Sep  4 12:23:20 PDT 2011
