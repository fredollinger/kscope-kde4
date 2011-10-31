
#include <KConfig>
#include <KConfigGroup>

#include <qdebug.h>

#include "ksconfig4.h"

//usr/include/KDE/../kconfig.h:177:5: note:                 KConfig::KConfig(const QString&, const QString&, const char*)
namespace kscope4{
KSConfig::KSConfig(const QString &qs) : KConfig(qs),
	m_group("") 
{}

void KSConfig::setGroup(const char* group){
	m_group = group;
}

unsigned int KSConfig::readUnsignedNumEntry(const char* key, int i){
	KConfigGroup gp(this, m_group);
	return (unsigned int) gp.readEntry(key, i);
}

unsigned int KSConfig::readUnsignedNumEntry(const char* key){
	int i = 0;
	KConfigGroup gp(this, m_group);
	return (unsigned int) gp.readEntry(key, i);
}

QString KSConfig::readEntry(const char* key){
	KConfigGroup gp(this, m_group);
	return gp.readEntry(key);
}

QString KSConfig::readEntry(const char* key, char *def){
	const char *cdef = def;
	KConfigGroup gp(this, m_group);
	return gp.readEntry(key,cdef);
}

QString KSConfig::readEntry(const char* key, QString def){
	KConfigGroup gp(this, m_group);
	return gp.readEntry(key,def);
}

QStringList KSConfig::readListEntry(const char* key, char* def){
	KConfigGroup gp(this, m_group);
	QVariant qv;
	const char *cdef = def;

	qv = gp.readEntry(key, cdef);
	return qv.toStringList();
}

bool KSConfig::readBoolEntry(const char* key, bool def){
	bool res = NULL;

	KConfigGroup gp(this, m_group);
	QVariant qv;

	qv = gp.readEntry(key);

	res = qv.toBool();
	if (NULL == res) return def;
	return res;
}

bool KSConfig::readBoolEntry(const char* key){
	bool res = NULL;

	KConfigGroup gp(this, m_group);
	QVariant qv;

	qv = gp.readEntry(key);

	res = qv.toBool();
	return res;
}

int KSConfig::readNumEntry(const char* key){
	int res = 0;

	KConfigGroup gp(this, m_group);
	QVariant qv;

	qv = gp.readEntry(key);

	res = qv.toInt();

	return res;
}

QStringList KSConfig::readListEntry(const char* key){
	KConfigGroup gp(this, m_group);
	QVariant qv;
	const char *cdef = "";

	qv = gp.readEntry(key, cdef);
	return qv.toStringList();
}

void KSConfig::writeEntry(const char* key, QStringList val){
	KConfigGroup gp(this, m_group);
	return gp.writeEntry(key, val);
}

void KSConfig::writeEntry(const char* key, QString val){
	KConfigGroup gp(this, m_group);
	return gp.writeEntry(key, val);
}

void KSConfig::writeEntry(const char* key, int val){
	KConfigGroup gp(this, m_group);
	return gp.writeEntry(key, val);
}

} // namespace kscope4
// Sun Oct 30 18:25:59 PDT 2011
