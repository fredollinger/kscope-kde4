#include "ksession.h"
#include <QList>
#include <QDebug>

namespace kscope4{
KSession::KSession() : QWidget()
{
}

KSession::~KSession() 
{
}

QStringList KSession::toStringList() const
{
	return fllOpenFiles.stringListFromFlList();
}

void KSession::FromStringList(const QStringList& sl) 
{
	fllOpenFiles.flListFromStringList(sl);
	return;
}

} // namespace kscope4
// Sat Mar 10 19:22:41 PST 2012
