/****************************************************************************
** Meta object code from reading C++ file 'emoticonselector.h'
**
** Created: Mon Apr 27 15:02:05 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "emoticonselector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emoticonselector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmoticonSelector[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      28,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EmoticonSelector[] = {
    "EmoticonSelector\0\0name,code\0"
    "smileySelected(QString,QString)\0"
    "addSmiley()\0"
};

const QMetaObject EmoticonSelector::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EmoticonSelector,
      qt_meta_data_EmoticonSelector, 0 }
};

const QMetaObject *EmoticonSelector::metaObject() const
{
    return &staticMetaObject;
}

void *EmoticonSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmoticonSelector))
	return static_cast<void*>(const_cast< EmoticonSelector*>(this));
    return QDialog::qt_metacast(_clname);
}

int EmoticonSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: smileySelected((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: addSmiley(); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void EmoticonSelector::smileySelected(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
