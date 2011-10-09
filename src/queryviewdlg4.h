#ifndef QUERYVIEWDLG_H
#define QUERYVIEWDLG_H

#include "queryviewlayout4.h"
#include "queryview4.h"

class QueryViewDriver;

/**
 * A dialogue for running and displaying queries.
 * The dialogue is built around a QueryView widget, and uses a QueryViewDriver
 * object to run a query. The dialogue is used in different contexts, such
 * as executing quick definitions, displaying multiple call nodes in a graph,
 * etc.
 * The dialogue is always modal, but should not be launched using exec().
 * Instead, it is created as a modeless, hidden, dialogue. It then becomes
 * modal (and visible) only if and when information is available (@see
 * QueryViewDriver::show()).
 * @author Elad Lahav
 */
class QueryViewDlg : public QDialog, public Ui::QueryViewLayout
{
	Q_OBJECT

public:
	QueryViewDlg(uint nFlags = 0, QWidget* pParent = 0, 
		const char* szName = 0);
	~QueryViewDlg();

	/** These flags control the behaviour of the dialogue. */
	enum { CloseOnSelect = 0x1, DestroyOnClose = 0x2,
		DestroyOnSelect = CloseOnSelect | DestroyOnClose };
	
	void query(uint, const QString&, bool bCase = true);

	QueryView::Iterator getIterator();

signals:
	/**
	 * Propagates the lineRequested() signal of the embedded QueryView
	 * widget.
	 * @param	sFile	The "File" field of the selected record
	 * @param	nLine	The "Line" field of the selected record
	 */
	void lineRequested(const QString& sFile, uint nLine);

private:
	/** Flags the control the behaviour of the dialogue. */
	uint m_nFlags;
	
	/** Used for running Cscope queries and displaying their results in the
		view. */
	QueryViewDriver* m_pDriver;
	
private slots:
	void slotShow();
	void slotLineRequested(const QString&, uint);
};

#endif

// Sun Oct  9 13:03:15 PDT 2011
