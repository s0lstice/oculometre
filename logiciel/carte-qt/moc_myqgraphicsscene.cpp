/****************************************************************************
** Meta object code from reading C++ file 'myqgraphicsscene.h'
**
** Created: Wed May 23 14:36:48 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myqgraphicsscene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myqgraphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyQGraphicsScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x0a,
      53,   17,   17,   17, 0x2a,
      65,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyQGraphicsScene[] = {
    "MyQGraphicsScene\0\0zones\0"
    "drawZones(Groupe_selection*)\0drawZones()\0"
    "DrawVolontaires()\0"
};

void MyQGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyQGraphicsScene *_t = static_cast<MyQGraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->drawZones((*reinterpret_cast< Groupe_selection*(*)>(_a[1]))); break;
        case 1: _t->drawZones(); break;
        case 2: _t->DrawVolontaires(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyQGraphicsScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyQGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_MyQGraphicsScene,
      qt_meta_data_MyQGraphicsScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyQGraphicsScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyQGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyQGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyQGraphicsScene))
        return static_cast<void*>(const_cast< MyQGraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int MyQGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
