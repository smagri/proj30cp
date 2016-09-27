/****************************************************************************
** Meta object code from reading C++ file 'ambulance.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ambulance/ambulance.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ambulance.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ambulance[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      49,   10,   10,   10, 0x08,
      85,   80,   10,   10, 0x08,
     128,   10,   10,   10, 0x08,
     169,   10,   10,   10, 0x08,
     201,   10,   10,   10, 0x08,
     235,   10,   10,   10, 0x08,
     267,   10,   10,   10, 0x08,
     306,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ambulance[] = {
    "ambulance\0\0on_deliverPayloadPushButton_clicked()\0"
    "on_sendSMSPushButton_clicked()\0arg1\0"
    "on_modemDevNameComboBox_activated(QString)\0"
    "on_stepperNumRotations_editingFinished()\0"
    "on_microAdjPushButton_clicked()\0"
    "on_winchDownRadioButton_clicked()\0"
    "on_winchUpRadioButton_clicked()\0"
    "on_mobileNumLineEdit_editingFinished()\0"
    "on_messageTextTextEdit_textChanged()\0"
};

void ambulance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ambulance *_t = static_cast<ambulance *>(_o);
        switch (_id) {
        case 0: _t->on_deliverPayloadPushButton_clicked(); break;
        case 1: _t->on_sendSMSPushButton_clicked(); break;
        case 2: _t->on_modemDevNameComboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_stepperNumRotations_editingFinished(); break;
        case 4: _t->on_microAdjPushButton_clicked(); break;
        case 5: _t->on_winchDownRadioButton_clicked(); break;
        case 6: _t->on_winchUpRadioButton_clicked(); break;
        case 7: _t->on_mobileNumLineEdit_editingFinished(); break;
        case 8: _t->on_messageTextTextEdit_textChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ambulance::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ambulance::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ambulance,
      qt_meta_data_ambulance, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ambulance::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ambulance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ambulance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ambulance))
        return static_cast<void*>(const_cast< ambulance*>(this));
    return QWidget::qt_metacast(_clname);
}

int ambulance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
