/****************************************************************************
** Meta object code from reading C++ file 'BDProprietesDesCpts.h'
**
** Created: Sun 25. Aug 17:57:00 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BDProprietesDesCpts.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BDProprietesDesCpts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BDProprietesDesCpts[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      42,   21,   20,   20, 0x0a,
      83,   75,   20,   20, 0x0a,
     118,   20,   20,   20, 0x08,
     140,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BDProprietesDesCpts[] = {
    "BDProprietesDesCpts\0\0afficher,designation\0"
    "afficherProprietes(bool,QString)\0"
    "transfo\0afficherProprietes(Transformateur)\0"
    "on_Triphase_clicked()\0on_Monophase_clicked()\0"
};

const QMetaObject BDProprietesDesCpts::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BDProprietesDesCpts,
      qt_meta_data_BDProprietesDesCpts, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BDProprietesDesCpts::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BDProprietesDesCpts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BDProprietesDesCpts::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BDProprietesDesCpts))
        return static_cast<void*>(const_cast< BDProprietesDesCpts*>(this));
    return QDialog::qt_metacast(_clname);
}

int BDProprietesDesCpts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: afficherProprietes((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: afficherProprietes((*reinterpret_cast< const Transformateur(*)>(_a[1]))); break;
        case 2: on_Triphase_clicked(); break;
        case 3: on_Monophase_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
