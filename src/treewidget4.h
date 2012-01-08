#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include "queryview4.h"
#include "encoder4.h"

class QueryViewDriver;

/**
 * A tree-like widget displaying a hierarchical list of functions.
 * The widget has two modes: called functions and calling functions. Depending
 * on this mode, child items represent functions called by or calling their
 * parent item.
 * @author Elad Lahav
 */
namespace kscope4{
class TreeWidget : public QueryView
{
	Q_OBJECT
	
public:
	TreeWidget(QWidget* pParent = 0, const char* szName = 0);
	~TreeWidget();
	
	/**
	 * The type of tree to display.
	 */
	enum Mode { Called, Calling };
	
	void setMode(Mode);
	void setRoot(const QString&);
	void queryRoot();
	void save(FILE*);
	
	virtual void addRecord(const QString&, const QString&, const QString&,
		const QString&, QListViewItem4*);
	virtual void queryFinished(uint, QListViewItem4*);
	
protected slots:
	virtual void slotSearch(QListViewItem4*, const QRegExp&, int);
	virtual void slotShowAll(QListViewItem4*);
	
private:
	/** The CscopeFrontend query type to use (based on the current mode). */
	uint m_nQueryType;
	
	/** Runs queries and outputs the results as tree items. */
	QueryViewDriver* m_pDriver;
	
	void saveItems(QListViewItem4*, QTextStream&, Encoder&);
	
private slots:
	void slotQueryItem(QListViewItem4*);
};
}// namespace kscope4

#endif
// Fri Nov 25 12:49:35 PST 2011
