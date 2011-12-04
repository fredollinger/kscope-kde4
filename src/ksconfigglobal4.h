#ifndef KSCONFIG_GLOBAL_H
#define KSCONFIG_GLOBAL_H
/**
 * KSConfigGlobal, a wrapper for global kconfig object
 * 
 * @author Fred Ollinger
 * 
 */

#include <KConfig>
#include <KConfigGroup>

#include <qdebug.h>

#include "KSGlobalConfig.h"

namespace kscope4{
class KSConfigGlobal : public KSGlobalConfig 
{
public:
	KSConfigGlobal();
	~KSConfigGlobal();

private:
	QString m_group; // what group we have
	KConfigGroup m_gp;

};

} // namespace kscope4
#endif // KSCONFIG_H
// Sun Oct 30 09:06:19 PDT 2011
