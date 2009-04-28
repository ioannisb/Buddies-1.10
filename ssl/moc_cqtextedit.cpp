/****************************************************************************
** Meta object code from reading C++ file 'cqtextedit.h'
**
** Created: Mon Apr 27 15:02:04 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cqtextedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cqtextedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cqtextedit[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      44,   24,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     115,   11,   11,   11, 0x0a,
     124,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_cqtextedit[] = {
    "cqtextedit\0\0focusLost()\0origin,source,dummy\0"
    "fileSendInitiated(QString,int,int)\0"
    "enableCopyPaste()\0enableDragnDrop()\0"
    "reload()\0animate()\0"
};

const QMetaObject cqtextedit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_cqtextedit,
      qt_meta_data_cqtextedit, 0 }
};

const QMetaObject *cqtextedit::metaObject() const
{
    return &staticMetaObject;
}

void *cqtextedit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cqtextedit))
	return static_cast<void*>(const_cast< cqtextedit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int cqtextedit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: focusLost(); break;
        case 1: fileSendInitiated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: enableCopyPaste(); break;
        case 3: enableDragnDrop(); break;
        case 4: reload(); break;
        case 5: animate(); break;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void cqtextedit::focusLost()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void cqtextedit::fileSendInitiated(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
