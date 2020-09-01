/****************************************************************************
** Meta object code from reading C++ file 'BDFormulaireDeRecepteur.h'
**
** Created: Sun 25. Aug 17:56:53 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BDFormulaireDeRecepteur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BDFormulaireDeRecepteur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BDFormulaireDeRecepteur[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x08,
      52,   24,   24,   24, 0x08,
      87,   24,   24,   24, 0x08,
     125,   24,   24,   24, 0x08,
     169,   24,   24,   24, 0x08,
     191,   24,   24,   24, 0x08,
     220,  214,   24,   24, 0x08,
     264,  214,   24,   24, 0x08,
     308,   24,   24,   24, 0x08,
     364,   24,   24,   24, 0x08,
     412,   24,   24,   24, 0x08,
     457,   24,   24,   24, 0x08,
     497,   24,   24,   24, 0x08,
     531,   24,   24,   24, 0x08,
     562,   24,   24,   24, 0x08,
     602,   24,   24,   24, 0x08,
     646,   24,   24,   24, 0x08,
     693,   24,   24,   24, 0x08,
     740,   24,   24,   24, 0x08,
     784,   24,   24,   24, 0x08,
     828,   24,   24,   24, 0x08,
     865,   24,   24,   24, 0x08,
     890,   24,   24,   24, 0x08,
     910,   24,   24,   24, 0x08,
     933,   24,   24,   24, 0x08,
     964,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BDFormulaireDeRecepteur[] = {
    "BDFormulaireDeRecepteur\0\0"
    "on_btn_predefini_clicked()\0"
    "on_radioButtonPutile_toggled(bool)\0"
    "on_radioButtonPabsorbee_toggled(bool)\0"
    "on_radioButtonCourant_Tension_toggled(bool)\0"
    "on_Triphase_clicked()\0on_Monophase_clicked()\0"
    "index\0on_comboBoxUnitePA_currentIndexChanged(int)\0"
    "on_comboBoxUnitePU_currentIndexChanged(int)\0"
    "on_comboBoxTypeDeRecepteur_currentIndexChanged(QString)\0"
    "on_comboBoxTension_currentIndexChanged(QString)\0"
    "on_doubleSpinBoxCourant_valueChanged(double)\0"
    "on_radioButtonCourant_Tension_clicked()\0"
    "on_radioButtonPabsorbee_clicked()\0"
    "on_radioButtonPutile_clicked()\0"
    "on_doubleSpinBoxKu_valueChanged(double)\0"
    "on_doubleSpinBoxCosPhi_valueChanged(double)\0"
    "on_doubleSpinBoxPabsorbee_valueChanged(double)\0"
    "on_doubleSpinBoxRendement_valueChanged(double)\0"
    "on_doubleSpinBoxPutile_valueChanged(double)\0"
    "on_lineEditDesignation_textChanged(QString)\0"
    "on_spinBoxQuantite_valueChanged(int)\0"
    "on_btn_Annuler_clicked()\0on_btn_OK_clicked()\0"
    "setPUtileEnabled(bool)\0"
    "setCourantTensionEnabled(bool)\0"
    "setPAbsorbeeEnabled(bool)\0"
};

const QMetaObject BDFormulaireDeRecepteur::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BDFormulaireDeRecepteur,
      qt_meta_data_BDFormulaireDeRecepteur, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BDFormulaireDeRecepteur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BDFormulaireDeRecepteur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BDFormulaireDeRecepteur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BDFormulaireDeRecepteur))
        return static_cast<void*>(const_cast< BDFormulaireDeRecepteur*>(this));
    return QDialog::qt_metacast(_clname);
}

int BDFormulaireDeRecepteur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_predefini_clicked(); break;
        case 1: on_radioButtonPutile_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_radioButtonPabsorbee_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: on_radioButtonCourant_Tension_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_Triphase_clicked(); break;
        case 5: on_Monophase_clicked(); break;
        case 6: on_comboBoxUnitePA_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_comboBoxUnitePU_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_comboBoxTypeDeRecepteur_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_comboBoxTension_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_doubleSpinBoxCourant_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: on_radioButtonCourant_Tension_clicked(); break;
        case 12: on_radioButtonPabsorbee_clicked(); break;
        case 13: on_radioButtonPutile_clicked(); break;
        case 14: on_doubleSpinBoxKu_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: on_doubleSpinBoxCosPhi_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: on_doubleSpinBoxPabsorbee_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: on_doubleSpinBoxRendement_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: on_doubleSpinBoxPutile_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: on_lineEditDesignation_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: on_spinBoxQuantite_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: on_btn_Annuler_clicked(); break;
        case 22: on_btn_OK_clicked(); break;
        case 23: setPUtileEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: setCourantTensionEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: setPAbsorbeeEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
