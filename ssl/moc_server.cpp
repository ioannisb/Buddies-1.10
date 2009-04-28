/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created: Mon Apr 27 15:02:10 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SslServer[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_SslServer[] = {
    "SslServer\0"
};

const QMetaObject SslServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_SslServer,
      qt_meta_data_SslServer, 0 }
};

const QMetaObject *SslServer::metaObject() const
{
    return &staticMetaObject;
}

void *SslServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SslServer))
	return static_cast<void*>(const_cast< SslServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int SslServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_sslConnection[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_sslConnection[] = {
    "sslConnection\0"
};

const QMetaObject sslConnection::staticMetaObject = {
    { &QSslSocket::staticMetaObject, qt_meta_stringdata_sslConnection,
      qt_meta_data_sslConnection, 0 }
};

const QMetaObject *sslConnection::metaObject() const
{
    return &staticMetaObject;
}

void *sslConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sslConnection))
	return static_cast<void*>(const_cast< sslConnection*>(this));
    return QSslSocket::qt_metacast(_clname);
}

int sslConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSslSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_Server[] = {

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
      55,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      76,    7,    7,    7, 0x0a,
      95,    7,    7,    7, 0x0a,
     116,    7,    7,    7, 0x0a,
     141,  137,    7,    7, 0x0a,
     169,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Server[] = {
    "Server\0\0readyToSendData()\0msg\0"
    "messageReceived(QString)\0serverDisconnected()\0"
    "acceptConnection()\0connectionAccepted()\0"
    "readDataFromClient()\0err\0"
    "sslErrors(QList<QSslError>)\0"
    "notifyDisconnect()\0"
};

const QMetaObject Server::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Server,
      qt_meta_data_Server, 0 }
};

const QMetaObject *Server::metaObject() const
{
    return &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server))
	return static_cast<void*>(const_cast< Server*>(this));
    return QWidget::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: readyToSendData(); break;
        case 1: messageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: serverDisconnected(); break;
        case 3: acceptConnection(); break;
        case 4: connectionAccepted(); break;
        case 5: readDataFromClient(); break;
        case 6: sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 7: notifyDisconnect(); break;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Server::readyToSendData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Server::messageReceived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::serverDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
