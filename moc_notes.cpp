/****************************************************************************
** Meta object code from reading C++ file 'notes.h'
**
** Created: Fri Apr 24 15:14:40 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "notes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Notes[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      18,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Notes[] = {
    "Notes\0\0addNotes()\0showNotes()\0"
};

const QMetaObject Notes::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Notes,
      qt_meta_data_Notes, 0 }
};

const QMetaObject *Notes::metaObject() const
{
    return &staticMetaObject;
}

void *Notes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Notes))
	return static_cast<void*>(const_cast< Notes*>(this));
    return QDialog::qt_metacast(_clname);
}

int Notes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addNotes(); break;
        case 1: showNotes(); break;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
