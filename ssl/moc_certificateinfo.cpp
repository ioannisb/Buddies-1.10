/****************************************************************************
** Meta object code from reading C++ file 'certificateinfo.h'
**
** Created: Mon Apr 27 15:02:02 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "certificateinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'certificateinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CertificateInfo[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CertificateInfo[] = {
    "CertificateInfo\0\0index\0"
    "updateCertificateInfo(int)\0"
};

const QMetaObject CertificateInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CertificateInfo,
      qt_meta_data_CertificateInfo, 0 }
};

const QMetaObject *CertificateInfo::metaObject() const
{
    return &staticMetaObject;
}

void *CertificateInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CertificateInfo))
	return static_cast<void*>(const_cast< CertificateInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int CertificateInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateCertificateInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
