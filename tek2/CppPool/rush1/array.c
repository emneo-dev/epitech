/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "array.h"
#include "new.h"
#include "int.h"

typedef struct
{
    Container base;
    Class *_type;
    size_t _size;
    Object **_tab;
} ArrayClass;

typedef struct
{
    Iterator base;
    ArrayClass *_array;
    size_t _idx;
} ArrayIteratorClass;

static void ArrayIterator_ctor(ArrayIteratorClass *this, va_list *args)
{
    if (!this || !args)
        raise("NULL value given");
    this->_array = va_arg(*args, ArrayClass *);
    this->_idx = va_arg(*args, int);
}

static bool ArrayIterator_eq(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->_idx == other->_idx);
}

static bool ArrayIterator_gt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->_idx > other->_idx);
}

static bool ArrayIterator_lt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->_idx < other->_idx);
}

static void ArrayIterator_incr(ArrayIteratorClass *this)
{
    if (!this)
        raise("NULL value given");
    this->_idx += 1;
}

static Object *ArrayIterator_getval(ArrayIteratorClass *this)
{
    if (!this)
        raise("NULL value given");
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void ArrayIterator_setval(ArrayIteratorClass *this, ...)
{
    size_t pos = 0;
    va_list va;
    Object *new_obj = NULL;

    if (!this)
        raise("NULL value given");
    va_start(va, this);
    pos = this->_idx;
    if (pos >= this->_idx)
        raise("Index out of bounds");
    new_obj = va_new(this->_array->_type, &va);
    delete(this->_array->_tab[pos]);
    this->_array->_tab[pos] = new_obj;
    va_end(va);
}

static const ArrayIteratorClass ArrayIteratorDescr = {
    {
        /* Iterator struct */
        {
            /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&ArrayIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ArrayIterator_eq,
            .__gt__ = (binary_comparator_t)&ArrayIterator_gt,
            .__lt__ = (binary_comparator_t)&ArrayIterator_lt,
        },
        .__incr__ = (incr_t)&ArrayIterator_incr,
        .__getval__ = (getval_t)&ArrayIterator_getval,
        .__setval__ = (setval_t)&ArrayIterator_setval,
    },
    ._array = NULL,
    ._idx = 0};

static const Class *ArrayIterator = (const Class *)&ArrayIteratorDescr;

static void Array_ctor(ArrayClass *this, va_list *args)
{
    Class *class = (Class *)this;
    va_list va;

    if (!this || !args)
        raise("NULL value given");
    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    this->_tab = malloc(class->__size__ * (this->_size + 1));
    if (!this->_type)
        raise("Out of Memory");
    if (!this->_tab)
        raise("NULL value given");
    for (size_t i = 0; i < this->_size; i++) {
        va_copy(va, *args);
        this->_tab[i] = va_new(this->_type, &va);
    }
}

static void Array_dtor(ArrayClass *this)
{
    if (!this)
        raise("NULL value given");
    for (size_t i = 0; i < this->_size; i++)
        delete (this->_tab[i]);
    free(this->_tab);
}

static size_t Array_len(ArrayClass *this)
{
    if (!this)
        raise("NULL value given");
    return (this->_size);
}

static Iterator *Array_begin(ArrayClass *this)
{
    if (!this)
        raise("NULL value given");
    return (new (ArrayIterator, this, 0));
}

static Iterator *Array_end(ArrayClass *this)
{
    if (!this)
        raise("NULL value given");
    return (new (ArrayIterator, this, this->_size));
}

static Object *Array_getitem(ArrayClass *this, ...)
{
    va_list va;
    size_t index = 0;

    if (!this)
        raise("NULL value given");
    va_start(va, this);
    index = va_arg(va, size_t);
    if (index < this->_size)
        return (this->_tab[index]);
    return (NULL);
}

static void Array_setitem(ArrayClass *this, ...)
{
    size_t pos = 0;
    va_list va;
    Object *new_obj = NULL;

    if (!this)
        raise("NULL value given");
    va_start(va, this);
    pos = va_arg(va, size_t);
    if (pos >= this->_size)
        raise("Index out of bounds");
    new_obj = va_new(this->_type, &va);
    delete(this->_tab[pos]);
    this->_tab[pos] = new_obj;
    va_end(va);
}

static char *Array_tostring(ArrayClass *this)
{
    int len = 0;
    char *str = NULL;
    Class *obj_class = NULL;
    char *res = NULL;

    if (!this)
        raise("NULL value given");

    // calculate str size
    len += snprintf(NULL, 0, "<Array ()>");
    for (uint32_t i = 0; i < this->_size; i++) {
        if (!(this->_tab[i]))
            continue;
        obj_class = (Class *)(this->_tab[i]);
        if (obj_class->__str__) {
            str = obj_class->__str__(obj_class);
            if (!str)
                raise("Out of memory");
            len += strlen(str) + 2;
            free(str);
        }
        else {
            len += snprintf(NULL, 0, "<%s>, ", obj_class->__name__);
        }
        if (i == this->_size - 1)
                len -= 2;
    }

    // malloc str
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        raise("Out of Memory");

    // get string
    len = sprintf(res, "<Array (");
    for (uint32_t i = 0; i < this->_size; i++) {
        if (!(this->_tab[i]))
            continue;
        obj_class = (Class *)(this->_tab[i]);
        if (obj_class->__str__) {
            str = obj_class->__str__(obj_class);
            if (i != this->_size - 1)
                len += sprintf(&(res[len]), "%s, ", str);
            else
                len += sprintf(&(res[len]), "%s", str);
            free(str);
        }
        else {
            if (i != this->_size - 1)
                len += sprintf(&(res[len]), "<%s>, ", obj_class->__name__);
            else
                len += sprintf(&(res[len]), "<%s>", obj_class->__name__);
        }
    }
    len += sprintf(&(res[len]), ")>");
    res[len] = '\0';
    return res;
}

static const ArrayClass _descr = {
    {
        {
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&Array_ctor,
            .__dtor__ = (dtor_t)&Array_dtor,
            .__str__ = (to_string_t)&Array_tostring,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&Array_len,
        .__begin__ = (iter_t)&Array_begin,
        .__end__ = (iter_t)&Array_end,
        .__getitem__ = (getitem_t)&Array_getitem,
        .__setitem__ = (setitem_t)&Array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class *Array = (const Class *)&_descr;
