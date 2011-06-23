

#ifndef _KGITIFACE_H_
#define _KGITIFACE_H_

#include <dcopobject.h>

class kgitIface : virtual public DCOPObject
{
  K_DCOP
public:

k_dcop:
  virtual void openURL(QString url) = 0;
};

#endif // _KGITIFACE_H_
