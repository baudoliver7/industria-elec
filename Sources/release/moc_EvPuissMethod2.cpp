/****************************************************************************
** Meta object code from reading C++ file 'EvPuissMethod2.h'
**
** Created: Sun 25. Aug 18:30:07 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../EvPuissMethod2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EvPuissMethod2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EvPuissMethod2[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      34,   25,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   15,   15,   15, 0x08,
      92,   15,   15,   15, 0x08,
     119,   15,   15,   15, 0x08,
     146,   15,   15,   15, 0x08,
     187,   15,   15,   15, 0x08,
     219,  213,   15,   15, 0x08,
     263,   15,   15,   15, 0x08,
     292,   15,   15,   15, 0x08,
     336,  213,   15,   15, 0x08,
     380,   15,   15,   15, 0x08,
     409,  213,   15,   15, 0x08,
     451,  213,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EvPuissMethod2[] = {
    "EvPuissMethod2\0\0closed()\0modified\0"
    "windowIsModified(bool)\0"
    "on_btn_VoirTransfoAdapte_clicked()\0"
    "on_btn_predefini_clicked()\0"
    "on_btn_supprimer_clicked()\0"
    "updateEtatModifierSupprimer(QModelIndex)\0"
    "on_btn_modifier_clicked()\0index\0"
    "on_comboBoxNature2_currentIndexChanged(int)\0"
    "on_btn_initialiser_clicked()\0"
    "on_lineEditDesignation_textChanged(QString)\0"
    "on_comboBoxNature1_currentIndexChanged(int)\0"
    "on_btn_enregistrer_clicked()\0"
    "on_comboBoxType2_currentIndexChanged(int)\0"
    "on_comboBoxType1_currentIndexChanged(int)\0"
};

const QMetaObject EvPuissMethod2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EvPuissMethod2,
      qt_meta_data_EvPuissMethod2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EvPuissMethod2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EvPuissMethod2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EvPuissMethod2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EvPuissMethod2))
        return static_cast<void*>(const_cast< EvPuissMethod2*>(this));
    return QWidget::qt_metacast(_clname);
}

int EvPuissMethod2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: closed(); break;
        case 1: windowIsModified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_btn_VoirTransfoAdapte_clicked(); break;
        case 3: on_btn_predefini_clicked(); break;
        case 4: on_btn_supprimer_clicked(); break;
        case 5: updateEtatModifierSupprimer((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: on_btn_modifier_clicked(); break;
        case 7: on_comboBoxNature2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_btn_initialiser_clicked(); break;
        case 9: on_lineEditDesignation_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_comboBoxNature1_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: on_btn_enregistrer_clicked(); break;
        case 12: on_comboBoxType2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_comboBoxType1_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void EvPuissMethod2::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EvPuissMethod2::windowIsModified(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
