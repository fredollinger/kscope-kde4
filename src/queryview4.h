#ifndef QUERYVIEW_H
#define QUERYVIEW_H

#include <qregexp.h>
#include <QStringListModel>

#include <QListView>
#include <QWidget>
#include <QObject>

/**
 * A list view widget for displaying locations in the source code. Each record
 * (list item) represents a single line of code.
 * The main purpose of this class is for showing query results (@see
 * QueryViewDriver), but is can also serve as a base class for any widget
 * which needs to refer to locations in the source code (@see
 * HistoryView).
 * The view has 4 columns, for showing the file path, function name, line
 * number and line text of a code location.
 * The widget owns a popup menu which allows users to copy information
 * from records, filter records, and more.
 * @author Elad Lahav
 */
class QueryView : public QStringListModel
{
	Q_OBJECT
	
public:

	QueryView(QWidget*, const char*);
	// QueryView(QWidget* pParent = 0, const char* szName = 0);
	~QueryView();

};
#endif // QUERYVIEW_H
