

#ifndef _KGITPREF_H_
#define _KGITPREF_H_

#include <kdialogbase.h>
#include <qframe.h>

class kgitPrefPageOne;
class kgitPrefPageTwo;

class kgitPreferences : public KDialogBase
{
    Q_OBJECT
public:
    kgitPreferences();

private:
    kgitPrefPageOne *m_pageOne;
    kgitPrefPageTwo *m_pageTwo;
};

class kgitPrefPageOne : public QFrame
{
    Q_OBJECT
public:
    kgitPrefPageOne(QWidget *parent = 0);
};

class kgitPrefPageTwo : public QFrame
{
    Q_OBJECT
public:
    kgitPrefPageTwo(QWidget *parent = 0);
};

#endif // _KGITPREF_H_
