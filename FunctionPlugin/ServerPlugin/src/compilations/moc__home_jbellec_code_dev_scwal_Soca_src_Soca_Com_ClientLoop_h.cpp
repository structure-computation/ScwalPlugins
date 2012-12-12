/****************************************************************************
** Meta object code from reading C++ file 'ClientLoop.h'
**
** Created: Fri Oct 26 00:03:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Soca/src/Soca/Com/ClientLoop.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientLoop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientLoop[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      39,   27,   11,   11, 0x05,
      57,   11,   11,   11, 0x05,
      72,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClientLoop[] = {
    "ClientLoop\0\0disconnected()\0,n_callback\0"
    "_load(Model*,int)\0_model(Model*)\0"
    "_type(quint64)\0readyRead()\0aboutToClose()\0"
    "readChannelFinished()\0send_data()\0"
};

const QMetaObject ClientLoop::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientLoop,
      qt_meta_data_ClientLoop, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientLoop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientLoop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientLoop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientLoop))
        return static_cast<void*>(const_cast< ClientLoop*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientLoop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: disconnected(); break;
        case 1: _load((*reinterpret_cast< Model*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _model((*reinterpret_cast< Model*(*)>(_a[1]))); break;
        case 3: _type((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 4: readyRead(); break;
        case 5: aboutToClose(); break;
        case 6: readChannelFinished(); break;
        case 7: send_data(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ClientLoop::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ClientLoop::_load(Model * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientLoop::_model(Model * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientLoop::_type(quint64 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
