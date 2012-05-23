/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun May 20 21:47:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     133,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     284,   11,   11,   11, 0x08,
     347,   11,  342,   11, 0x08,
     361,   11,   11,   11, 0x08,
     401,   11,   11,   11, 0x08,
     441,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0ceratSelection()\0"
    "Selpoints_clicked()\0"
    "on_actionCharger_une_carte_triggered()\0"
    "on_actionCharger_des_Volontaires_triggered()\0"
    "on_actionQuiter_triggered()\0"
    "supprimer_Volontaires()\0creatGroup()\0"
    "creatRect()\0creatCercle()\0removeZone()\0"
    "drawVolontaires()\0drawZones()\0"
    "switchZoneEtat()\0"
    "on_actionAnalyse_des_zones_et_des_volontaires_triggered()\0"
    "bool\0saveDonnees()\0"
    "on_actionExporter_les_zones_triggered()\0"
    "on_actionImporter_des_zones_triggered()\0"
    "on_actionA_propos_de_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->ceratSelection(); break;
        case 1: _t->Selpoints_clicked(); break;
        case 2: _t->on_actionCharger_une_carte_triggered(); break;
        case 3: _t->on_actionCharger_des_Volontaires_triggered(); break;
        case 4: _t->on_actionQuiter_triggered(); break;
        case 5: _t->supprimer_Volontaires(); break;
        case 6: _t->creatGroup(); break;
        case 7: _t->creatRect(); break;
        case 8: _t->creatCercle(); break;
        case 9: _t->removeZone(); break;
        case 10: _t->drawVolontaires(); break;
        case 11: _t->drawZones(); break;
        case 12: _t->switchZoneEtat(); break;
        case 13: _t->on_actionAnalyse_des_zones_et_des_volontaires_triggered(); break;
        case 14: { bool _r = _t->saveDonnees();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: _t->on_actionExporter_les_zones_triggered(); break;
        case 16: _t->on_actionImporter_des_zones_triggered(); break;
        case 17: _t->on_actionA_propos_de_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
