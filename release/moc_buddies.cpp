/****************************************************************************
** Meta object code from reading C++ file 'buddies.h'
**
** Created: Tue Apr 28 12:31:28 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../buddies.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buddies.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Buddies[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      28,    8,    8,    8, 0x0a,
      44,    8,    8,    8, 0x0a,
      56,    8,    8,    8, 0x0a,
      77,    8,    8,    8, 0x0a,
      92,    8,    8,    8, 0x0a,
     113,    8,    8,    8, 0x0a,
     122,    8,    8,    8, 0x0a,
     137,    8,    8,    8, 0x0a,
     150,    8,    8,    8, 0x0a,
     162,    8,    8,    8, 0x0a,
     174,    8,    8,    8, 0x0a,
     187,    8,    8,    8, 0x0a,
     202,    8,    8,    8, 0x0a,
     216,    8,    8,    8, 0x0a,
     230,    8,    8,    8, 0x0a,
     241,    8,    8,    8, 0x0a,
     253,    8,    8,    8, 0x0a,
     270,  264,    8,    8, 0x08,
     290,  283,    8,    8, 0x08,
     339,    8,    8,    8, 0x08,
     356,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Buddies[] = {
    "Buddies\0\0countOnlineUsers()\0setUserStatus()\0"
    "loginUser()\0loginCurrentStatus()\0"
    "validateUser()\0stopifNotConnected()\0"
    "myexit()\0focusTabEdit()\0structUser()\0"
    "startChat()\0helpAbout()\0getSysInfo()\0"
    "onlineNotify()\0WriteOnWall()\0Information()\0"
    "dbstatus()\0openNotes()\0startSSL()\0"
    "index\0setIcon(int)\0reason\0"
    "iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "messageClicked()\0showMessage()\0"
};

const QMetaObject Buddies::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Buddies,
      qt_meta_data_Buddies, 0 }
};

const QMetaObject *Buddies::metaObject() const
{
    return &staticMetaObject;
}

void *Buddies::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Buddies))
	return static_cast<void*>(const_cast< Buddies*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Buddies::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: countOnlineUsers(); break;
        case 1: setUserStatus(); break;
        case 2: loginUser(); break;
        case 3: loginCurrentStatus(); break;
        case 4: validateUser(); break;
        case 5: stopifNotConnected(); break;
        case 6: myexit(); break;
        case 7: focusTabEdit(); break;
        case 8: structUser(); break;
        case 9: startChat(); break;
        case 10: helpAbout(); break;
        case 11: getSysInfo(); break;
        case 12: onlineNotify(); break;
        case 13: WriteOnWall(); break;
        case 14: Information(); break;
        case 15: dbstatus(); break;
        case 16: openNotes(); break;
        case 17: startSSL(); break;
        case 18: setIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 20: messageClicked(); break;
        case 21: showMessage(); break;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
