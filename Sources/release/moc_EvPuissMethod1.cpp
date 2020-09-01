/****************************************************************************
** Meta object code from reading C++ file 'EvPuissMethod1.h'
**
** Created: Sun 25. Aug 18:14:31 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../EvPuissMethod1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EvPuissMethod1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EvPuissMethod1[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      25,   15,   15,   15, 0x05,
      47,   39,   15,   15, 0x05,
      74,   39,   15,   15, 0x05,
     108,   99,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     133,  131,   15,   15, 0x0a,
     163,   15,   15,   15, 0x0a,
     193,   15,   15,   15, 0x0a,
     234,  222,   15,   15, 0x0a,
     262,  222,   15,   15, 0x0a,
     292,  222,   15,   15, 0x0a,
     318,   15,   15,   15, 0x08,
     336,  222,   15,   15, 0x08,
     395,  366,  361,   15, 0x08,
     480,  457,   15,   15, 0x08,
     570,  540,   15,   15, 0x08,
     631,  457,   15,   15, 0x28,
     712,  688,  361,   15, 0x08,
     753,  457,   15,   15, 0x08,
     844,  819,   15,   15, 0x08,
     902,  884,   15,   15, 0x28,
     938,  222,   15,   15, 0x08,
     965,  688,  361,   15, 0x08,
    1002,  884,   15,   15, 0x08,
    1037,  819,   15,   15, 0x08,
    1073,  884,   15,   15, 0x28,
    1105,  222,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EvPuissMethod1[] = {
    "EvPuissMethod1\0\0closed()\0etatChanged()\0"
    "enabled\0enableAllerEnArriere(bool)\0"
    "enableAllerEnAvant(bool)\0modified\0"
    "windowIsModified(bool)\0i\0"
    "setInstallation(Installation)\0"
    "agrandirInstallationGraphic()\0"
    "reduireInstallationGraphic()\0designation\0"
    "supprimerUnTableau(QString)\0"
    "supprimerUnRecepteur(QString)\0"
    "supprimerUnLocal(QString)\0sauvegarderEtat()\0"
    "editerUnTableau(QString)\0bool\0"
    "title,designationParent,type\0"
    "creerUnNouveauTableau(QString,QString,Tableau::TypeDeTableau)\0"
    "designationParent,type\0"
    "creerDirectUnNouveauTableau(QString,Tableau::TypeDeTableau)\0"
    "designationParent,type,nombre\0"
    "creerDesNouveauxTableaux(QString,Tableau::TypeDeTableau,int)\0"
    "creerDesNouveauxTableaux(QString,Tableau::TypeDeTableau)\0"
    "title,designationParent\0"
    "creerUnNouveauRecepteur(QString,QString)\0"
    "creerDirectUnNouveauRecepteur(QString,Recepteur::TypeDeRecepteur)\0"
    "designationParent,nombre\0"
    "creerDesNouveauxRecepteurs(QString,int)\0"
    "designationParent\0creerDesNouveauxRecepteurs(QString)\0"
    "editerUnRecepteur(QString)\0"
    "creerUnNouveauLocal(QString,QString)\0"
    "creerDirectUnNouveauLocal(QString)\0"
    "creerDesNouveauxLocaux(QString,int)\0"
    "creerDesNouveauxLocaux(QString)\0"
    "editerUnLocal(QString)\0"
};

const QMetaObject EvPuissMethod1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EvPuissMethod1,
      qt_meta_data_EvPuissMethod1, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EvPuissMethod1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EvPuissMethod1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EvPuissMethod1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EvPuissMethod1))
        return static_cast<void*>(const_cast< EvPuissMethod1*>(this));
    return QWidget::qt_metacast(_clname);
}

int EvPuissMethod1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: closed(); break;
        case 1: etatChanged(); break;
        case 2: enableAllerEnArriere((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: enableAllerEnAvant((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: windowIsModified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: setInstallation((*reinterpret_cast< const Installation(*)>(_a[1]))); break;
        case 6: agrandirInstallationGraphic(); break;
        case 7: reduireInstallationGraphic(); break;
        case 8: supprimerUnTableau((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: supprimerUnRecepteur((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: supprimerUnLocal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: sauvegarderEtat(); break;
        case 12: editerUnTableau((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: { bool _r = creerUnNouveauTableau((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< Tableau::TypeDeTableau(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: creerDirectUnNouveauTableau((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Tableau::TypeDeTableau(*)>(_a[2]))); break;
        case 15: creerDesNouveauxTableaux((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Tableau::TypeDeTableau(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: creerDesNouveauxTableaux((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Tableau::TypeDeTableau(*)>(_a[2]))); break;
        case 17: { bool _r = creerUnNouveauRecepteur((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: creerDirectUnNouveauRecepteur((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Recepteur::TypeDeRecepteur(*)>(_a[2]))); break;
        case 19: creerDesNouveauxRecepteurs((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: creerDesNouveauxRecepteurs((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: editerUnRecepteur((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: { bool _r = creerUnNouveauLocal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: creerDirectUnNouveauLocal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: creerDesNouveauxLocaux((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: creerDesNouveauxLocaux((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: editerUnLocal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void EvPuissMethod1::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EvPuissMethod1::etatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void EvPuissMethod1::enableAllerEnArriere(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EvPuissMethod1::enableAllerEnAvant(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EvPuissMethod1::windowIsModified(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
