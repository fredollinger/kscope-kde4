#include <QStackedWidget>
#include <qdebug.h>

namespace kscope4{

///home/follinge/projects/kscope-kde4/src/build/../queryview4.h :28:68: error: no matching function for call to ‘kscope4::QListViewItem::QListViewItem(QListView*&, kscope4::QListViewItem*&)’
QListViewItem::QListViewItem : QTreeView()
{
	qDebug() <<"QListViewItem::QListViewItem() FIXME\n";
}

QListViewItem::QListViewItem( QListView *parent, QListViewItem *after){
	qDebug() <<"QListViewItem::QListViewItem() FIXME\n";
}

QListViewItem::QListViewItem( QListViewItem *parent, QListViewItem *after){
	qDebug() <<"QListViewItem::QListViewItem() FIXME\n";
}

/**
 */
QListViewItem::~QListViewItem 
{
	// close();
}

} // namespace kscope4

// Sun Sep  4 12:23:20 PDT 2011
