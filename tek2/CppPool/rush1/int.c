/*
** EPITECH PROJECT, 2021
** int
** File description:
** int
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int value;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this || !args)
        raise("NULL value given");
    this->value = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    ssize_t bufsz = 0;
    char* buf = NULL;

    if (!this)
        raise("NULL value given");
    bufsz = snprintf(NULL, 0, "<Int (%d)>", this->value);
    buf = malloc(bufsz + 1);
    if (!buf)
        raise("Out of Memory");
    snprintf(buf, bufsz + 1, "<Int (%d)>", this->value);
    return (buf);
}

static IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    IntClass *new_int = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_int = new(Int, this->value + other->value);
    return (new_int);
}

static IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    IntClass *new_int = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_int = new(Int, this->value - other->value);
    return (new_int);
}

static IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    IntClass *new_int = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_int = new(Int, this->value * other->value);
    return (new_int);
}

static IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    IntClass *new_int = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_int = new(Int, this->value / other->value);
    return (new_int);
}

bool Int_eq(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value == other->value);
}

bool Int_gt(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value > other->value);
}

bool Int_lt(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value < other->value);
}

static const IntClass _description = {
    {
     .__size__ = sizeof(IntClass),
     .__name__ = "Int",
     .__ctor__ = (ctor_t)&Int_ctor,
     .__dtor__ = (dtor_t)&Int_dtor,
     .__str__ = (to_string_t)&Int_str,
     .__add__ = (binary_operator_t)&Int_add,
     .__sub__ = (binary_operator_t)&Int_sub,
     .__mul__ = (binary_operator_t)&Int_mul,
     .__div__ = (binary_operator_t)&Int_div,
     .__eq__ = (binary_comparator_t)&Int_eq,
     .__gt__ = (binary_comparator_t)&Int_gt,
     .__lt__ = (binary_comparator_t)&Int_lt
    },
    .value = 0
};

const Class *Int = (const Class *)&_description;
