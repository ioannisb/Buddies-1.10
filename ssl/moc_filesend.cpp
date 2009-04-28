/****************************************************************************
** Meta object code from reading C++ file 'filesend.h'
**
** Created: Mon Apr 27 15:02:06 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filesend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fileSend[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      21,    9,    9,    9, 0x05,
      34,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   49,    9,    9, 0x0a,
     101,   87,    9,    9, 0x0a,
     146,  141,    9,    9, 0x0a,
     170,    9,    9,    9, 0x0a,
     192,    9,    9,    9, 0x0a,
     208,    9,    9,    9, 0x0a,
     230,  227,    9,    9, 0x0a,
     250,    9,    9,    9, 0x0a,
     263,    9,    9,    9, 0x0a,
     277,    9,    9,    9, 0x0a,
     293,    9,    9,    9, 0x0a,
     313,    9,    9,    9, 0x0a,
     333,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_fileSend[] = {
    "fileSend\0\0finished()\0successful()\0"
    "fileRejected()\0f,p,size\0"
    "sendFile(QString,int,qint64)\0f,p,size,host\0"
    "receiveFile(QString,int,qint64,QString)\0"
    "data\0receiveData(QByteArray)\0"
    "initiateTransaction()\0endConnection()\0"
    "disconnectClient()\0dp\0acceptFile(QString)\0"
    "rejectFile()\0actOnReject()\0actOnComplete()\0"
    "cancelTransaction()\0updateProgressBar()\0"
    "sendAChunk()\0"
};

const QMetaObject fileSend::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fileSend,
      qt_meta_data_fileSend, 0 }
};

const QMetaObject *fileSend::metaObject() const
{
    return &staticMetaObject;
}

void *fileSend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fileSend))
	return static_cast<void*>(const_cast< fileSend*>(this));
    return QWidget::qt_metacast(_clname);
}

int fileSend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished(); break;
        case 1: successful(); break;
        case 2: fileRejected(); break;
        case 3: sendFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 4: receiveFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 5: receiveData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: initiateTransaction(); break;
        case 7: endConnection(); break;
        case 8: disconnectClient(); break;
        case 9: acceptFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: rejectFile(); break;
        case 11: actOnReject(); break;
        case 12: actOnComplete(); break;
        case 13: cancelTransaction(); break;
        case 14: updateProgressBar(); break;
        case 15: sendAChunk(); break;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void fileSend::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void fileSend::successful()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void fileSend::fileRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
