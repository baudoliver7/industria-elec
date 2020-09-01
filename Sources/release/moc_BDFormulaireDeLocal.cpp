/****************************************************************************
** Meta object code from reading C++ file 'BDFormulaireDeLocal.h'
**
** Created: Sun 25. Aug 17:57:03 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BDFormulaireDeLocal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BDFormulaireDeLocal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BDFormulaireDeLocal[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      41,   20,   20,   20, 0x08,
      66,   20,   20,   20, 0x08,
     114,   20,   20,   20, 0x08,
     151,   20,   20,   20, 0x08,
     200,   20,   20,   20, 0x08,
     250,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BDFormulaireDeLocal[] = {
    "BDFormulaireDeLocal\0\0on_btn_OK_clicked()\0"
    "on_btn_Annuler_clicked()\0"
    "on_doubleSpinBoxSuperficie_valueChanged(double)\0"
    "on_spinBoxPEstimee_valueChanged(int)\0"
    "on_comboBoxTypeUtil_currentIndexChanged(QString)\0"
    "on_comboBoxTypeLocal_currentIndexChanged(QString)\0"
    "on_lineEditDesignation_textChanged(QString)\0"
};

const QMetaObject BDFormulaireDeLocal::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BDFormulaireDeLocal,
      qt_meta_data_BDFormulaireDeLocal, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BDFormulaireDeLocal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BDFormulaireDeLocal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BDFormulaireDeLocal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BDFormulaireDeLocal))
        return static_cast<void*>(const_cast< BDFormulaireDeLocal*>(this));
    return QDialog::qt_metacast(_clname);
}

int BDFormulaireDeLocal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_OK_clicked(); break;
        case 1: on_btn_Annuler_clicked(); break;
        case 2: on_doubleSpinBoxSuperficie_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: on_spinBoxPEstimee_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_comboBoxTypeUtil_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_comboBoxTypeLocal_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: on_lineEditDesignation_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
