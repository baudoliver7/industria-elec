/****************************************************************************
** Meta object code from reading C++ file 'BDParamTransfo.h'
**
** Created: Sun 25. Aug 17:57:06 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BDParamTransfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BDParamTransfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BDParamTransfo[] = {

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
      16,   15,   15,   15, 0x08,
      41,   15,   15,   15, 0x08,
      61,   15,   15,   15, 0x08,
      97,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BDParamTransfo[] = {
    "BDParamTransfo\0\0on_btn_Annuler_clicked()\0"
    "on_btn_OK_clicked()\0"
    "on_spinBoxTempAmb_valueChanged(int)\0"
    "on_doubleSpinBoxExtension_valueChanged(double)\0"
};

const QMetaObject BDParamTransfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BDParamTransfo,
      qt_meta_data_BDParamTransfo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BDParamTransfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BDParamTransfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BDParamTransfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BDParamTransfo))
        return static_cast<void*>(const_cast< BDParamTransfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int BDParamTransfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_Annuler_clicked(); break;
        case 1: on_btn_OK_clicked(); break;
        case 2: on_spinBoxTempAmb_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_doubleSpinBoxExtension_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
