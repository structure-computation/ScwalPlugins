/****************************************************************************
** Meta object code from reading C++ file 'SodaClient.h'
**
** Created: Tue Nov 5 11:21:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Soca/src/Soca/Com/SodaClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SodaClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SodaClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x08,
      52,   12,   11,   11, 0x08,
      81,   79,   11,   11, 0x08,
     109,  105,   11,   11, 0x08,
     143,  105,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SodaClient[] = {
    "SodaClient\0\0ptr\0reg_type_callback_auto_reg(quint64)\0"
    "reg_type_callback(quint64)\0m\0"
    "change_callback(Model*)\0m,n\0"
    "load_for_reg_callback(Model*,int)\0"
    "load_callback(Model*,int)\0disconnected()\0"
};

void SodaClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SodaClient *_t = static_cast<SodaClient *>(_o);
        switch (_id) {
        case 0: _t->reg_type_callback_auto_reg((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 1: _t->reg_type_callback((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: _t->change_callback((*reinterpret_cast< Model*(*)>(_a[1]))); break;
        case 3: _t->load_for_reg_callback((*reinterpret_cast< Model*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->load_callback((*reinterpret_cast< Model*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->disconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SodaClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SodaClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SodaClient,
      qt_meta_data_SodaClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SodaClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SodaClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SodaClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SodaClient))
        return static_cast<void*>(const_cast< SodaClient*>(this));
    return QObject::qt_metacast(_clname);
}

int SodaClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
