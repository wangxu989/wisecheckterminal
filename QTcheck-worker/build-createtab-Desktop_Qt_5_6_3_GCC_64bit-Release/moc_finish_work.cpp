/****************************************************************************
** Meta object code from reading C++ file 'finish_work.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../createtab/finish_work.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finish_work.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Program3__time_update_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Program3__time_update_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Program3__time_update_t qt_meta_stringdata_Program3__time_update = {
    {
QT_MOC_LITERAL(0, 0, 21) // "Program3::time_update"

    },
    "Program3::time_update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Program3__time_update[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Program3::time_update::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Program3::time_update::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Program3__time_update.data,
      qt_meta_data_Program3__time_update,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Program3::time_update::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Program3::time_update::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Program3__time_update.stringdata0))
        return static_cast<void*>(const_cast< time_update*>(this));
    return QThread::qt_metacast(_clname);
}

int Program3::time_update::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_Program3__finish_work_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Program3__finish_work_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Program3__finish_work_t qt_meta_stringdata_Program3__finish_work = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Program3::finish_work"
QT_MOC_LITERAL(1, 22, 15), // "invoke_keyboard"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 63, 12), // "label_change"
QT_MOC_LITERAL(5, 76, 8), // "MyLEdit*"
QT_MOC_LITERAL(6, 85, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 107, 11), // "in_keyboard"
QT_MOC_LITERAL(8, 119, 3), // "row"
QT_MOC_LITERAL(9, 123, 6) // "column"

    },
    "Program3::finish_work\0invoke_keyboard\0"
    "\0on_pushButton_2_clicked\0label_change\0"
    "MyLEdit*\0on_pushButton_clicked\0"
    "in_keyboard\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Program3__finish_work[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    2,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

       0        // eod
};

void Program3::finish_work::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        finish_work *_t = static_cast<finish_work *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->invoke_keyboard(); break;
        case 1: { QString _r = _t->on_pushButton_2_clicked();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: _t->label_change((*reinterpret_cast< MyLEdit*(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->in_keyboard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyLEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (finish_work::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&finish_work::invoke_keyboard)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Program3::finish_work::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Program3__finish_work.data,
      qt_meta_data_Program3__finish_work,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Program3::finish_work::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Program3::finish_work::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Program3__finish_work.stringdata0))
        return static_cast<void*>(const_cast< finish_work*>(this));
    return QWidget::qt_metacast(_clname);
}

int Program3::finish_work::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Program3::finish_work::invoke_keyboard()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
