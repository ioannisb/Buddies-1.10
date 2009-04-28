/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created: Mon Apr 27 15:02:03 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Client[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      30,   26,    7,    7, 0x05,
      60,   55,    7,    7, 0x05,
      85,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,    7,    7,    7, 0x0a,
     133,  127,    7,    7, 0x0a,
     182,    7,    7,    7, 0x0a,
     207,  203,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Client[] = {
    "Client\0\0readyToSendData()\0msg\0"
    "messageReceived(QString)\0data\0"
    "dataReceived(QByteArray)\0clientDisconnected()\0"
    "connectionAccepted()\0state\0"
    "socketStateChanged(QAbstractSocket::SocketState)\0"
    "readDataFromServer()\0err\0"
    "sslErrors(QList<QSslError>)\0"
};

const QMetaObject Client::staticMetaObject = {
    { &QSslSocket::staticMetaObject, qt_meta_stringdata_Client,
      qt_meta_data_Client, 0 }
};

const QMetaObject *Client::metaObject() const
{
    return &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Client))
	return static_cast<void*>(const_cast< Client*>(this));
    return QSslSocket::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSslSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: readyToSendData(); break;
        case 1: messageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: dataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: clientDisconnected(); break;
        case 4: connectionAccepted(); break;
        case 5: socketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 6: readDataFromServer(); break;
        case 7: sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Client::readyToSendData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Client::messageReceived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::dataReceived(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::clientDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
