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
	KSConfig();
	virtual ~KSConfig();
};

} // namespace kscope4
#endif // KSCONFIG_H
// Sun Oct 30 09:06:19 PDT 2011
