/*
** EPITECH PROJECT, 2021
** float.c
** File description:
** float
*/

#include "float.h"
#include "new.h"
#include <stdio.h>

typedef struct
{
    Class base;
    float value;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this || !args)
        raise("NULL value given");
    this->value = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (!this)
        raise("NULL value given");
}

static char *Float_str(FloatClass *this)
{
    ssize_t bufsz = 0;
    char* buf = malloc(bufsz + 1);

    if (!this)
        raise("NULL value given");
    else if (!buf)
        raise("Out of Memory");
    bufsz = snprintf(NULL, 0, "<Float (%f)>", this->value);
    snprintf(buf, bufsz + 1, "<Float (%f)>", this->value);
    return (buf);
}

static FloatClass *Float_add(const FloatClass *this, const FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_point = new(Float, this->value + other->value);
    return (new_point);
}

static FloatClass *Float_sub(const FloatClass *this, const FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_point = new(Float, this->value - other->value);
    return (new_point);
}

static FloatClass *Float_mul(const FloatClass *this, const FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_point = new(Float, this->value * other->value);
    return (new_point);
}

static FloatClass *Float_div(const FloatClass *this, const FloatClass *other)
{
    FloatClass *new_point = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_point = new(Float, this->value / other->value);
    return (new_point);
}

bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value == other->value);
}

bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value > other->value);
}

bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value < other->value);
}

static const FloatClass _description = {
    {
     .__size__ = sizeof(FloatClass),
     .__name__ = "Float",
     .__ctor__ = (ctor_t)&Float_ctor,
     .__dtor__ = (dtor_t)&Float_dtor,
     .__str__ = (to_string_t)&Float_str,
     .__add__ = (binary_operator_t)&Float_add,
     .__sub__ = (binary_operator_t)&Float_sub,
     .__mul__ = (binary_operator_t)&Float_mul,
     .__div__ = (binary_operator_t)&Float_div,
     .__eq__ = (binary_comparator_t)&Float_eq,
     .__gt__ = (binary_comparator_t)&Float_gt,
     .__lt__ = (binary_comparator_t)&Float_lt,
    },
    .value = 0
};

const Class *Float = (const Class *)&_description;

// JE VAIS LE FLOAT ALEXAAAANDRE