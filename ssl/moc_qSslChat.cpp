/****************************************************************************
** Meta object code from reading C++ file 'qSslChat.h'
**
** Created: Mon Apr 27 15:02:09 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qSslChat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qSslChat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qSslChat[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      33,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,    9,    9,    9, 0x0a,
      64,    9,    9,    9, 0x0a,
      80,    9,    9,    9, 0x0a,
     103,  101,    9,    9, 0x0a,
     124,  120,    9,    9, 0x0a,
     148,    9,    9,    9, 0x0a,
     161,    9,    9,    9, 0x0a,
     177,    9,    9,    9, 0x0a,
     213,  196,    9,    9, 0x0a,
     239,    9,    9,    9, 0x0a,
     254,    9,    9,    9, 0x0a,
     273,    9,    9,    9, 0x0a,
     298,  288,    9,    9, 0x0a,
     328,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qSslChat[] = {
    "qSslChat\0\0peerRejectedFileSend()\0"
    "fsCompleted()\0hostConnection()\0"
    "connectToHost()\0activateMsgSending()\0"
    "s\0sendMsg(QString)\0msg\0receiveMessage(QString)\0"
    "displayMsg()\0endConnection()\0"
    "sendAnticipation()\0path,source,size\0"
    "sendFile(QString,int,int)\0notifyServer()\0"
    "completeFileSend()\0selectSmiley()\0"
    "name,code\0insertSmiley(QString,QString)\0"
    "displayCertificateInfo()\0"
};

const QMetaObject qSslChat::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qSslChat,
      qt_meta_data_qSslChat, 0 }
};

const QMetaObject *qSslChat::metaObject() const
{
    return &staticMetaObject;
}

void *qSslChat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qSslChat))
	return static_cast<void*>(const_cast< qSslChat*>(this));
    if (!strcmp(_clname, "Ui::qSslChat"))
	return static_cast< Ui::qSslChat*>(const_cast< qSslChat*>(this));
    return QWidget::qt_metacast(_clname);
}

int qSslChat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: peerRejectedFileSend(); break;
        case 1: fsCompleted(); break;
        case 2: hostConnection(); break;
        case 3: connectToHost(); break;
        case 4: activateMsgSending(); break;
        case 5: sendMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: receiveMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: displayMsg(); break;
        case 8: endConnection(); break;
        case 9: sendAnticipation(); break;
        case 10: sendFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: notifyServer(); break;
        case 12: completeFileSend(); break;
        case 13: selectSmiley(); break;
        case 14: insertSmiley((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: displayCertificateInfo(); break;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void qSslChat::peerRejectedFileSend()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qSslChat::fsCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
