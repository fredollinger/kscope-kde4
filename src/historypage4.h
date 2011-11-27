#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include "querypagebase4.h"

/**
 * A QueryWidget page for holding position history.
 * @author Elad Lahav
 */
namespace kscope4{
class HistoryPage : public QueryPageBase
{
	Q_OBJECT

public:
	HistoryPage(QWidget* pParent = 0, const char* szName = 0);
	~HistoryPage();
	
	void addRecord(const QString&, uint, const QString&);
	
	virtual QString getCaption(bool bBrief = false) const;

protected:
	virtual void addRecord(const QString&, const QString&, const QString&,
		const QString&);
	virtual QString getFileName(const QString&) const;
	
	/**
	 * @return	Always true, since History files do not contain a header
	 */
	virtual bool readHeader(QTextStream&) { return true; }
	
	/**
	 * This method does nothing, since History files do not contain a header.
	 */	
	virtual void writeHeader(QTextStream&) {}

private:
	/** A unique ID used to create a tab caption for this page. */
	int m_nPageID;

	/** Used to generate the unique page ID for each object. */
	static int s_nMaxPageID;
};
} // namespace kscope4
#endif
