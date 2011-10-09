#ifndef QUERYWIDGET_H
#define QUERYWIDGET_H

#include <QDockWidget>
#include <QListView>
#include <QObject>

/**
 * A tabbed-window holding Cscope query results pages.
 * @author Elad Lahav
*/

namespace kscope4{
class QueryWidget : public QDockWidget
{
   Q_OBJECT

public:
	QueryWidget(QWidget* pParent = 0, const char* szName = 0);
	~QueryWidget();

	void addQueryPage();
	void initQuery(uint, const QString&, bool);
	void applyPrefs();
	void loadPages(const QString&, const QStringList&);
	void savePages(const QString&, QStringList&);
	void addHistoryRecord(const QString&, uint, const QString&);
	void selectActiveHistory();

private:
	/** The number of query pages currently open. */
	int m_nQueryPages;

     	QDockWidget *resDock;
};
} // namespace kscope4

#endif
// Sun Sep  4 13:51:43 PDT 2011
