#ifndef QUERYPAGE_H
#define QUERYPAGE_H

#include <qwidget.h>
#include <qlistview.h>
#include <qregexp.h>
#include "querypagebase4.h"
#include "cscopefrontend4.h"
#include "querypage4.h"

class QueryViewDriver;

/**
 * A QueryWidget page that runs and displays Cscope queries.
 * The page uses a QueryViewDriver object to run queries, and an embedded
 * QueryView widget for displaying query results.
 * @author Elad Lahav
 */
namespace kscope4{
class QueryPage : public QueryPageBase
{
   Q_OBJECT

public: 
	QueryPage(QWidget* pParent = 0, const char* szName = 0);
	~QueryPage();
	
	void query(uint, const QString&, bool);
	void refresh();
	void clear();
	bool isRunning();
	
	virtual QString getCaption(bool bBrief = false) const;

protected:
	virtual void addRecord(const QString&, const QString&, const QString&,
		const QString&);
	virtual QString getFileName(const QString&) const;
	virtual bool readHeader(QTextStream&);
	virtual void writeHeader(QTextStream&);

private:
	/** The type of query whose results are listed on this page. */
	uint m_nType;
	
	/** The text given as a parameter to the query. */
	QString m_sText;
	
	/** Whether the query is case-sensitive. */
	bool m_bCase;
	
	/** A formatted caption for this query, including the type of query and
		its text. */
	QString m_sName;
	
private:
	/** Runs Cscope queries whose results are displayed in this page. */
	QueryViewDriver* m_pDriver;
};
} // namespace kscope4
#endif
// Fri Sep  2 12:20:48 PDT 2011
