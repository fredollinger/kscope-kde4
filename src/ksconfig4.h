#ifndef KSCONFIG_H
#define KSCONFIG_H
/**
 * KSConfig, a partial reimplementation KDE3 KConfig
 * 
 * Meant to be a drop in replacement 
 *
 * @author Fred Ollinger
 * 
 */

#include <KConfig>
#include <KConfigGroup>

#include <qdebug.h>

namespace kscope4{
class KSConfig : public KConfig 
{
public:
	KSConfig(const QString&);
	// virtual ~KSConfig();

	bool readBoolEntry(const char*);
	bool readBoolEntry(const char*, bool);

	QString readEntry(const char*);
	QString readEntry(const char*, char*);
	QString readEntry(const char*, QString);

	void writeEntry(const char*, int);
	void writeEntry(const char*, QString);
	void writeEntry(const char*, QStringList);

	QStringList readListEntry(const char*);
	QStringList readListEntry(const char*, char*);

	int readNumEntry(const char*);

	unsigned int readUnsignedNumEntry(const char*);
	unsigned int readUnsignedNumEntry(const char*, int);

	virtual void setGroup(const char*);

private:
	QString m_group; // what group we have
	KConfigGroup m_gp;
};

} // namespace kscope4
#endif // KSCONFIG_H
// Sun Oct 30 09:06:19 PDT 2011
