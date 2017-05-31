/****************************************************************************
** Meta object code from reading C++ file 'CmccClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CmccClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CmccClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CmccClass_t {
    QByteArrayData data[15];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CmccClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CmccClass_t qt_meta_stringdata_CmccClass = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CmccClass"
QT_MOC_LITERAL(1, 10, 17), // "replyPageInfoSlot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 44, 5), // "reply"
QT_MOC_LITERAL(5, 50, 14), // "replyLoginSlot"
QT_MOC_LITERAL(6, 65, 15), // "replyLogoutSlot"
QT_MOC_LITERAL(7, 81, 14), // "replyVcodeSlot"
QT_MOC_LITERAL(8, 96, 19), // "comboboxChangedSlot"
QT_MOC_LITERAL(9, 116, 5), // "index"
QT_MOC_LITERAL(10, 122, 14), // "deleteUserSlot"
QT_MOC_LITERAL(11, 137, 9), // "loginSlot"
QT_MOC_LITERAL(12, 147, 10), // "logoutSlot"
QT_MOC_LITERAL(13, 158, 10), // "getsmsSlot"
QT_MOC_LITERAL(14, 169, 12) // "getVcodeSlot"

    },
    "CmccClass\0replyPageInfoSlot\0\0"
    "QNetworkReply*\0reply\0replyLoginSlot\0"
    "replyLogoutSlot\0replyVcodeSlot\0"
    "comboboxChangedSlot\0index\0deleteUserSlot\0"
    "loginSlot\0logoutSlot\0getsmsSlot\0"
    "getVcodeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CmccClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       6,    1,   70,    2, 0x08 /* Private */,
       7,    1,   73,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CmccClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CmccClass *_t = static_cast<CmccClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyPageInfoSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->replyLoginSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->replyLogoutSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->replyVcodeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->comboboxChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->deleteUserSlot(); break;
        case 6: _t->loginSlot(); break;
        case 7: _t->logoutSlot(); break;
        case 8: _t->getsmsSlot(); break;
        case 9: _t->getVcodeSlot(); break;
        default: ;
        }
    }
}

const QMetaObject CmccClass::staticMetaObject = {
    { &NetClass::staticMetaObject, qt_meta_stringdata_CmccClass.data,
      qt_meta_data_CmccClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CmccClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CmccClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CmccClass.stringdata0))
        return static_cast<void*>(const_cast< CmccClass*>(this));
    return NetClass::qt_metacast(_clname);
}

int CmccClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NetClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
