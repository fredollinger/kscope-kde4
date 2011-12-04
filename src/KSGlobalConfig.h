// This file is generated by kconfig_compiler from KSGlobalConfig.kcfg.
// All changes you do to this file will be lost.
#ifndef KSCOPE4_KSGLOBALCONFIG_H
#define KSCOPE4_KSGLOBALCONFIG_H

#include <kglobal.h>
#include <kconfigskeleton.h>
#include <kdebug.h>

#include <kglobalsettings.h>
namespace kscope4 {

class KSGlobalConfig : public KConfigSkeleton
{
  public:

    KSGlobalConfig( );
    ~KSGlobalConfig();


    /**
      Get List of recent projects
    */
    QStringList recentProjects() const
    {
      return mRecentProjects;
    }

  protected:

    // Projects
    QStringList mRecentProjects;

  private:
};

}

#endif

