/****************************************************************************
** Meta object code from reading C++ file 'render_area.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/render_area.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'render_area.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_render_area[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   13,   12,   12, 0x05,
      51,   45,   12,   12, 0x05,
      78,   74,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_render_area[] = {
    "render_area\0\0nombre_de_vie\0vie_generale(int)\0"
    "score\0updatescorejoueur(int)\0a,b\0"
    "updatealien(int,int)\0update_timer()\0"
};

void render_area::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        render_area *_t = static_cast<render_area *>(_o);
        switch (_id) {
        case 0: _t->vie_generale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updatescorejoueur((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updatealien((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->update_timer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData render_area::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject render_area::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_render_area,
      qt_meta_data_render_area, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &render_area::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *render_area::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *render_area::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_render_area))
        return static_cast<void*>(const_cast< render_area*>(this));
    return QWidget::qt_metacast(_clname);
}

int render_area::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void render_area::vie_generale(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void render_area::updatescorejoueur(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void render_area::updatealien(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
