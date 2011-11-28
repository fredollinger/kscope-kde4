
#include <KConfig>
#include <KGlobal>
#include <KConfigGroup>

#include <qdebug.h>

#include "ksconfigglobal4.h"
#include "ksconfig4.h"

//usr/include/KDE/../kconfig.h:177:5: note:                 KConfig::KConfig(const QString&, const QString&, const char*)
namespace kscope4{
KSConfigGlobal::KSConfigGlobal(const QString &qs) : KSConfig(qs), 
	m_group("")
{

	// KConfig* pConf = KGlobal::config();
	// m_gp(kglobal::config(), "");
}

} // namespace kscope4
// Sun Nov 27 19:57:17 PST 2011
