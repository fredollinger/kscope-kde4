
#include <KConfig>
#include <KConfigGroup>

#include <qdebug.h>

#include "ksconfig4.h"

//usr/include/KDE/../kconfig.h:177:5: note:                 KConfig::KConfig(const QString&, const QString&, const char*)
namespace kscope4{
KSConfig::KSConfig(const QString &qs) : KConfig(qs),
	m_group(""),
	m_gp(this, "")
{}

void KSConfig::setGroup(const char* group){
	m_group = group;
}

unsigned int KSConfig::readUnsignedNumEntry(const char* key, int i){
	m_gp.changeGroup(m_group);
	qDebug() << "ksconfig(): number: " <<  m_gp.readEntry(key, i) << " group: " << m_group;
	// stops a dumb bug
	if ( m_group.isEmpty() ) {
	// 	qDebug() << "ksconfig(): empty: " << readEntry(key, i);
	}
	return (unsigned int) m_gp.readEntry(key, i);
}

unsigned int KSConfig::readUnsignedNumEntry(const char* key){
	int i = 0;
	m_gp.changeGroup(m_group);
	return (unsigned int) m_gp.readEntry(key, i);
}

QString KSConfig::readEntry(const char* key){
	m_gp.changeGroup(m_group);
	return m_gp.readEntry(key);
}

QString KSConfig::readEntry(const char* key, char *def){
	const char *cdef = def;
	m_gp.changeGroup(m_group);
	return m_gp.readEntry(key,cdef);
}

QString KSConfig::readEntry(const char* key, QString def){
	m_gp.changeGroup(m_group);
	return m_gp.readEntry(key,def);
}

QStringList KSConfig::readListEntry(const char* key, char* def){
	m_gp.changeGroup(m_group);
	QVariant qv;
	const char *cdef = def;

	qv = m_gp.readEntry(key, cdef);
	return qv.toStringList();
}

bool KSConfig::readBoolEntry(const char* key, bool def){
	m_gp.changeGroup(m_group);

	bool res = NULL;

	QVariant qv;

	qv = m_gp.readEntry(key);

	res = qv.toBool();
	if (NULL == res) return def;
	return res;
}

bool KSConfig::readBoolEntry(const char* key){
	bool res = NULL;

	m_gp.changeGroup(m_group);
	QVariant qv;

	qv = m_gp.readEntry(key);

	res = qv.toBool();
	return res;
}

int KSConfig::readNumEntry(const char* key){
	int res = 0;

	m_gp.changeGroup(m_group);
	QVariant qv;

	qv = m_gp.readEntry(key);

	res = qv.toInt();

	return res;
}

QStringList KSConfig::readListEntry(const char* key){
	m_gp.changeGroup(m_group);
	QVariant qv;
	const char *cdef = "";

	qv = m_gp.readEntry(key, cdef);
	return qv.toStringList();
}

void KSConfig::writeEntry(const char* key, QStringList val){
	m_gp.changeGroup(m_group);
	return m_gp.writeEntry(key, val);
}

void KSConfig::writeEntry(const char* key, QString val){
	m_gp.changeGroup(m_group);
	return m_gp.writeEntry(key, val);
}

void KSConfig::writeEntry(const char* key, int val){
	m_gp.changeGroup(m_group);
	return m_gp.writeEntry(key, val);
}

} // namespace kscope4
// Sun Nov 13 14:10:46 PST 2011
