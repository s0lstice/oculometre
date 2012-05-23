/****************************************************************************
** Meta object code from reading C++ file 'mytreezonemodel.h'
**
** Created: Sun May 20 21:47:41 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mytreezonemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytreezonemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyTreeZoneModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x0a,
      53,   16,   16,   16, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_MyTreeZoneModel[] = {
    "MyTreeZoneModel\0\0zones\0"
    "switchEtat(Groupe_selection*)\0"
    "switchEtat()\0"
};

void MyTreeZoneModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTreeZoneModel *_t = static_cast<MyTreeZoneModel *>(_o);
        switch (_id) {
        case 0: _t->switchEtat((*reinterpret_cast< Groupe_selection*(*)>(_a[1]))); break;
        case 1: _t->switchEtat(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyTreeZoneModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyTreeZoneModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_MyTreeZoneModel,
      qt_meta_data_MyTreeZoneModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyTreeZoneModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyTreeZoneModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyTreeZoneModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTreeZoneModel))
        return static_cast<void*>(const_cast< MyTreeZoneModel*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int MyTreeZoneModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
