/****************************************************************************
** Meta object code from reading C++ file 'kscope4.h'
**
** Created: Wed Mar 9 15:09:46 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kscope4.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kscope4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KScope[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_KScope[] = {
    "KScope\0"
};

const QMetaObject KScope::staticMetaObject = {
    { &KParts::MainWindow::staticMetaObject, qt_meta_stringdata_KScope,
      qt_meta_data_KScope, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KScope::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KScope::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KScope::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KScope))
        return static_cast<void*>(const_cast< KScope*>(this));
    typedef KParts::MainWindow QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int KScope::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef KParts::MainWindow QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
