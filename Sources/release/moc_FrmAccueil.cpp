/****************************************************************************
** Meta object code from reading C++ file 'FrmAccueil.h'
**
** Created: Sun 25. Aug 17:57:13 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FrmAccueil.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrmAccueil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FrmAccueil[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      26,   11,   11,   11, 0x05,
      40,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FrmAccueil[] = {
    "FrmAccueil\0\0createNewMI()\0createNewMT()\0"
    "openProject()\0on_btn_new_mt_clicked()\0"
    "on_btn_new_mi_clicked()\0"
    "on_btn_open_project_clicked()\0"
};

const QMetaObject FrmAccueil::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FrmAccueil,
      qt_meta_data_FrmAccueil, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FrmAccueil::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FrmAccueil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FrmAccueil::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FrmAccueil))
        return static_cast<void*>(const_cast< FrmAccueil*>(this));
    return QWidget::qt_metacast(_clname);
}

int FrmAccueil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: createNewMI(); break;
        case 1: createNewMT(); break;
        case 2: openProject(); break;
        case 3: on_btn_new_mt_clicked(); break;
        case 4: on_btn_new_mi_clicked(); break;
        case 5: on_btn_open_project_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FrmAccueil::createNewMI()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FrmAccueil::createNewMT()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FrmAccueil::openProject()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
