/****************************************************************************
** Meta object code from reading C++ file 'LnnuClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LnnuClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LnnuClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LnnuClass_t {
    QByteArrayData data[18];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LnnuClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LnnuClass_t qt_meta_stringdata_LnnuClass = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LnnuClass"
QT_MOC_LITERAL(1, 10, 14), // "replyLoginSlot"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 41, 5), // "reply"
QT_MOC_LITERAL(5, 47, 16), // "replyConnectSlot"
QT_MOC_LITERAL(6, 64, 14), // "replyVCodeSlot"
QT_MOC_LITERAL(7, 79, 13), // "replyInfoSlot"
QT_MOC_LITERAL(8, 93, 13), // "sendLoginInfo"
QT_MOC_LITERAL(9, 107, 14), // "sendLogOutInfo"
QT_MOC_LITERAL(10, 122, 18), // "sendGetPictureInfo"
QT_MOC_LITERAL(11, 141, 11), // "sendGetInfo"
QT_MOC_LITERAL(12, 153, 11), // "connectSlot"
QT_MOC_LITERAL(13, 165, 14), // "buypackageSlot"
QT_MOC_LITERAL(14, 180, 10), // "detailSlot"
QT_MOC_LITERAL(15, 191, 23), // "LnnuComboBoxChangedSlot"
QT_MOC_LITERAL(16, 215, 5), // "index"
QT_MOC_LITERAL(17, 221, 17) // "DelUserButtonSlot"

    },
    "LnnuClass\0replyLoginSlot\0\0QNetworkReply*\0"
    "reply\0replyConnectSlot\0replyVCodeSlot\0"
    "replyInfoSlot\0sendLoginInfo\0sendLogOutInfo\0"
    "sendGetPictureInfo\0sendGetInfo\0"
    "connectSlot\0buypackageSlot\0detailSlot\0"
    "LnnuComboBoxChangedSlot\0index\0"
    "DelUserButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LnnuClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       7,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x0a /* Public */,
       9,    0,   92,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    1,   98,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,

       0        // eod
};

void LnnuClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LnnuClass *_t = static_cast<LnnuClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyLoginSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->replyConnectSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->replyVCodeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->replyInfoSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->sendLoginInfo(); break;
        case 5: _t->sendLogOutInfo(); break;
        case 6: _t->sendGetPictureInfo(); break;
        case 7: _t->sendGetInfo(); break;
        case 8: _t->connectSlot(); break;
        case 9: _t->buypackageSlot(); break;
        case 10: _t->detailSlot(); break;
        case 11: _t->LnnuComboBoxChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->DelUserButtonSlot(); break;
        default: ;
        }
    }
}

const QMetaObject LnnuClass::staticMetaObject = {
    { &NetClass::staticMetaObject, qt_meta_stringdata_LnnuClass.data,
      qt_meta_data_LnnuClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LnnuClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LnnuClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LnnuClass.stringdata0))
        return static_cast<void*>(const_cast< LnnuClass*>(this));
    return NetClass::qt_metacast(_clname);
}

int LnnuClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NetClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
struct qt_meta_stringdata_LnnuPayPackageClass_t {
    QByteArrayData data[3];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LnnuPayPackageClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LnnuPayPackageClass_t qt_meta_stringdata_LnnuPayPackageClass = {
    {
QT_MOC_LITERAL(0, 0, 19), // "LnnuPayPackageClass"
QT_MOC_LITERAL(1, 20, 17), // "postPayActionSlot"
QT_MOC_LITERAL(2, 38, 0) // ""

    },
    "LnnuPayPackageClass\0postPayActionSlot\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LnnuPayPackageClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void LnnuPayPackageClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LnnuPayPackageClass *_t = static_cast<LnnuPayPackageClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->postPayActionSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LnnuPayPackageClass::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LnnuPayPackageClass.data,
      qt_meta_data_LnnuPayPackageClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LnnuPayPackageClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LnnuPayPackageClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LnnuPayPackageClass.stringdata0))
        return static_cast<void*>(const_cast< LnnuPayPackageClass*>(this));
    return QDialog::qt_metacast(_clname);
}

int LnnuPayPackageClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
