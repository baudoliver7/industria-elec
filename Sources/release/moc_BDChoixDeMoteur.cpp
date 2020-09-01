/****************************************************************************
** Meta object code from reading C++ file 'BDChoixDeMoteur.h'
**
** Created: Sun 25. Aug 17:57:08 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BDChoixDeMoteur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BDChoixDeMoteur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BDChoixDeMoteur[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      42,   16,   16,   16, 0x08,
      62,   16,   16,   16, 0x08,
     120,  115,   16,   16, 0x08,
     149,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BDChoixDeMoteur[] = {
    "BDChoixDeMoteur\0\0on_btn_Annuler_clicked()\0"
    "on_btn_OK_clicked()\0"
    "on_comboBoxTypeDeMoteur_currentIndexChanged(QString)\0"
    "type\0selectionnerMoteurs(QString)\0"
    "updateBtnOK(QModelIndex)\0"
};

const QMetaObject BDChoixDeMoteur::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BDChoixDeMoteur,
      qt_meta_data_BDChoixDeMoteur, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BDChoixDeMoteur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BDChoixDeMoteur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BDChoixDeMoteur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BDChoixDeMoteur))
        return static_cast<void*>(const_cast< BDChoixDeMoteur*>(this));
    return QDialog::qt_metacast(_clname);
}

int BDChoixDeMoteur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_Annuler_clicked(); break;
        case 1: on_btn_OK_clicked(); break;
        case 2: on_comboBoxTypeDeMoteur_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: selectionnerMoteurs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: updateBtnOK((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
