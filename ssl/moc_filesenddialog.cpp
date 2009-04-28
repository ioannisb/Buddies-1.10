/****************************************************************************
** Meta object code from reading C++ file 'filesenddialog.h'
**
** Created: Mon Apr 27 15:02:07 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filesenddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesenddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fileSendDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x05,
      43,   15,   15,   15, 0x05,
      58,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   15,   15,   15, 0x0a,
      94,   15,   15,   15, 0x0a,
     107,   15,   15,   15, 0x0a,
     133,  127,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_fileSendDialog[] = {
    "fileSendDialog\0\0path\0acceptedFile(QString)\0"
    "rejectedFile()\0transactionCancelled()\0"
    "acceptFile()\0rejectFile()\0cancelTransaction()\0"
    "value\0updateProgressDialog(int)\0"
};

const QMetaObject fileSendDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fileSendDialog,
      qt_meta_data_fileSendDialog, 0 }
};

const QMetaObject *fileSendDialog::metaObject() const
{
    return &staticMetaObject;
}

void *fileSendDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fileSendDialog))
	return static_cast<void*>(const_cast< fileSendDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int fileSendDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: acceptedFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: rejectedFile(); break;
        case 2: transactionCancelled(); break;
        case 3: acceptFile(); break;
        case 4: rejectFile(); break;
        case 5: cancelTransaction(); break;
        case 6: updateProgressDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void fileSendDialog::acceptedFile(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fileSendDialog::rejectedFile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void fileSendDialog::transactionCancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
