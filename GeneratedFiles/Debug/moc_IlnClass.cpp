/****************************************************************************
** Meta object code from reading C++ file 'IlnClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IlnClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IlnClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IlnClass_t {
    QByteArrayData data[22];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IlnClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IlnClass_t qt_meta_stringdata_IlnClass = {
    {
QT_MOC_LITERAL(0, 0, 8), // "IlnClass"
QT_MOC_LITERAL(1, 9, 15), // "replyCookieSlot"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 41, 5), // "reply"
QT_MOC_LITERAL(5, 47, 14), // "replyLoginSlot"
QT_MOC_LITERAL(6, 62, 16), // "replyConnectSlot"
QT_MOC_LITERAL(7, 79, 13), // "replyInfoSlot"
QT_MOC_LITERAL(8, 93, 12), // "replySmsSlot"
QT_MOC_LITERAL(9, 106, 17), // "pawLetextEditSlot"
QT_MOC_LITERAL(10, 124, 4), // "text"
QT_MOC_LITERAL(11, 129, 13), // "sendLoginInfo"
QT_MOC_LITERAL(12, 143, 14), // "sendLogOutInfo"
QT_MOC_LITERAL(13, 158, 15), // "sendConnectInfo"
QT_MOC_LITERAL(14, 174, 18), // "sendDisConnectInfo"
QT_MOC_LITERAL(15, 193, 11), // "sendSmsInfo"
QT_MOC_LITERAL(16, 205, 19), // "comboBoxChangedSlot"
QT_MOC_LITERAL(17, 225, 5), // "index"
QT_MOC_LITERAL(18, 231, 17), // "delUserButtonSlot"
QT_MOC_LITERAL(19, 249, 11), // "serviceSlot"
QT_MOC_LITERAL(20, 261, 16), // "rechargeCardSlot"
QT_MOC_LITERAL(21, 278, 14) // "updataInfoSlot"

    },
    "IlnClass\0replyCookieSlot\0\0QNetworkReply*\0"
    "reply\0replyLoginSlot\0replyConnectSlot\0"
    "replyInfoSlot\0replySmsSlot\0pawLetextEditSlot\0"
    "text\0sendLoginInfo\0sendLogOutInfo\0"
    "sendConnectInfo\0sendDisConnectInfo\0"
    "sendSmsInfo\0comboBoxChangedSlot\0index\0"
    "delUserButtonSlot\0serviceSlot\0"
    "rechargeCardSlot\0updataInfoSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IlnClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       5,    1,   97,    2, 0x08 /* Private */,
       6,    1,  100,    2, 0x08 /* Private */,
       7,    1,  103,    2, 0x08 /* Private */,
       8,    1,  106,    2, 0x08 /* Private */,
       9,    1,  109,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x0a /* Public */,
      12,    0,  113,    2, 0x0a /* Public */,
      13,    0,  114,    2, 0x0a /* Public */,
      14,    0,  115,    2, 0x0a /* Public */,
      15,    0,  116,    2, 0x0a /* Public */,
      16,    1,  117,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IlnClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IlnClass *_t = static_cast<IlnClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyCookieSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->replyLoginSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->replyConnectSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->replyInfoSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->replySmsSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->pawLetextEditSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->sendLoginInfo(); break;
        case 7: _t->sendLogOutInfo(); break;
        case 8: _t->sendConnectInfo(); break;
        case 9: _t->sendDisConnectInfo(); break;
        case 10: _t->sendSmsInfo(); break;
        case 11: _t->comboBoxChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->delUserButtonSlot(); break;
        case 13: _t->serviceSlot(); break;
        case 14: _t->rechargeCardSlot(); break;
        case 15: _t->updataInfoSlot(); break;
        default: ;
        }
    }
}

const QMetaObject IlnClass::staticMetaObject = {
    { &NetClass::staticMetaObject, qt_meta_stringdata_IlnClass.data,
      qt_meta_data_IlnClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IlnClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IlnClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IlnClass.stringdata0))
        return static_cast<void*>(const_cast< IlnClass*>(this));
    return NetClass::qt_metacast(_clname);
}

int IlnClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NetClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
struct qt_meta_stringdata_IlnCardClass_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IlnCardClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IlnCardClass_t qt_meta_stringdata_IlnCardClass = {
    {
QT_MOC_LITERAL(0, 0, 12), // "IlnCardClass"
QT_MOC_LITERAL(1, 13, 6), // "updata"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "getPicSlot"
QT_MOC_LITERAL(4, 32, 14), // "postActiveSlot"
QT_MOC_LITERAL(5, 47, 17), // "replyPageInfoSlot"
QT_MOC_LITERAL(6, 65, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 80, 5), // "reply"
QT_MOC_LITERAL(8, 86, 15) // "replyActiveSlot"

    },
    "IlnCardClass\0updata\0\0getPicSlot\0"
    "postActiveSlot\0replyPageInfoSlot\0"
    "QNetworkReply*\0reply\0replyActiveSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IlnCardClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void IlnCardClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IlnCardClass *_t = static_cast<IlnCardClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updata(); break;
        case 1: _t->getPicSlot(); break;
        case 2: _t->postActiveSlot(); break;
        case 3: _t->replyPageInfoSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->replyActiveSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IlnCardClass::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IlnCardClass::updata)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject IlnCardClass::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IlnCardClass.data,
      qt_meta_data_IlnCardClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IlnCardClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IlnCardClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IlnCardClass.stringdata0))
        return static_cast<void*>(const_cast< IlnCardClass*>(this));
    return QDialog::qt_metacast(_clname);
}

int IlnCardClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void IlnCardClass::updata()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_IlnServiceClass_t {
    QByteArrayData data[17];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IlnServiceClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IlnServiceClass_t qt_meta_stringdata_IlnServiceClass = {
    {
QT_MOC_LITERAL(0, 0, 15), // "IlnServiceClass"
QT_MOC_LITERAL(1, 16, 17), // "replyPageInfoSlot"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 50, 5), // "reply"
QT_MOC_LITERAL(5, 56, 14), // "replyVcodeSlot"
QT_MOC_LITERAL(6, 71, 14), // "replyLoginSlot"
QT_MOC_LITERAL(7, 86, 17), // "replyBusinessSlot"
QT_MOC_LITERAL(8, 104, 23), // "usercomboBoxChangedSlot"
QT_MOC_LITERAL(9, 128, 5), // "index"
QT_MOC_LITERAL(10, 134, 23), // "cardcomboBoxChangedSlot"
QT_MOC_LITERAL(11, 158, 15), // "changeVcodeSlot"
QT_MOC_LITERAL(12, 174, 14), // "tabChangedSlot"
QT_MOC_LITERAL(13, 189, 16), // "loginServiceSlot"
QT_MOC_LITERAL(14, 206, 11), // "sendSmsSlot"
QT_MOC_LITERAL(15, 218, 15), // "forceLogoutSlot"
QT_MOC_LITERAL(16, 234, 17) // "getMyBusinessSlot"

    },
    "IlnServiceClass\0replyPageInfoSlot\0\0"
    "QNetworkReply*\0reply\0replyVcodeSlot\0"
    "replyLoginSlot\0replyBusinessSlot\0"
    "usercomboBoxChangedSlot\0index\0"
    "cardcomboBoxChangedSlot\0changeVcodeSlot\0"
    "tabChangedSlot\0loginServiceSlot\0"
    "sendSmsSlot\0forceLogoutSlot\0"
    "getMyBusinessSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IlnServiceClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       6,    1,   80,    2, 0x08 /* Private */,
       7,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    1,   93,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IlnServiceClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IlnServiceClass *_t = static_cast<IlnServiceClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyPageInfoSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->replyVcodeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->replyLoginSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->replyBusinessSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->usercomboBoxChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->cardcomboBoxChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->changeVcodeSlot(); break;
        case 7: _t->tabChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->loginServiceSlot(); break;
        case 9: _t->sendSmsSlot(); break;
        case 10: _t->forceLogoutSlot(); break;
        case 11: _t->getMyBusinessSlot(); break;
        default: ;
        }
    }
}

const QMetaObject IlnServiceClass::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IlnServiceClass.data,
      qt_meta_data_IlnServiceClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IlnServiceClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IlnServiceClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IlnServiceClass.stringdata0))
        return static_cast<void*>(const_cast< IlnServiceClass*>(this));
    return QDialog::qt_metacast(_clname);
}

int IlnServiceClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
