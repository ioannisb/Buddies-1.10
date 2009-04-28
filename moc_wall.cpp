/****************************************************************************
** Meta object code from reading C++ file 'wall.h'
**
** Created: Fri Apr 24 16:49:30 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wall.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wall.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Wall[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      13,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Wall[] = {
    "Wall\0\0send()\0wallreload()\0"
};

const QMetaObject Wall::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Wall,
      qt_meta_data_Wall, 0 }
};

const QMetaObject *Wall::metaObject() const
{
    return &staticMetaObject;
}

void *Wall::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Wall))
	return static_cast<void*>(const_cast< Wall*>(this));
    return QDialog::qt_metacast(_clname);
}

int Wall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: send(); break;
        case 1: wallreload(); break;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
