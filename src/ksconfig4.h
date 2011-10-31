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
	virtual ~KSConfig();

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

	void setGroup(const char*);

#if 0
/home/follinge/projects/kscope-kde4/src/project4.cpp:94:21: error: ‘class kscope4::KSConfig’ has no member named ‘readEntry’
/home/follinge/projects/kscope-kde4/src/project4.cpp: In member function ‘virtual QString Project::getFileTypes() const’:
/home/follinge/projects/kscope-kde4/src/project4.cpp:142:29: error: ‘class kscope4::KSConfig’ has no member named ‘readListEntry’
/home/follinge/projects/kscope-kde4/src/project4.cpp:143:25: error: ‘class kscope4::KSConfig’ has no member named ‘readBoolEntry’
/home/follinge/projects/kscope-kde4/src/project4.cpp:145:29: error: ‘class kscope4::KSConfig’ has no member named ‘readBoolEntry’
/home/follinge/projects/kscope-kde4/src/project4.cpp:147:34: error: ‘class kscope4::KSConfig’ has no member named ‘readNumEntry’
#endif

private:
	QString m_group; // what group we have
};

} // namespace kscope4
#endif // KSCONFIG_H
// Sun Oct 30 09:06:19 PDT 2011
