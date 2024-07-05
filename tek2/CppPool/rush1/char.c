/*
** EPITECH PROJECT, 2021
** char
** File description:
** char
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char value;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("NULL value given");
    this->value = (char)va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        raise("NULL value given");
}

static char *Char_str(CharClass *this)
{
    ssize_t bufsz = 0;
    char* buf = malloc(bufsz + 1);

    if (!this)
        raise("NULL value given");
    bufsz = snprintf(NULL, 0, "<Char (%c)>", this->value);
    if (!buf)
        raise("Out of Memory");
    snprintf(buf, bufsz + 1, "<Char (%c)>", this->value);
    return (buf);
}

static CharClass *Char_add(const CharClass *this, const CharClass *other)
{
    CharClass *new_char = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_char = new(Char, this->value + other->value);
    return (new_char);
}

static CharClass *Char_sub(const CharClass *this, const CharClass *other)
{
    CharClass *new_char = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_char = new(Char, this->value - other->value);
    return (new_char);
}

static CharClass *Char_mul(const CharClass *this, const CharClass *other)
{
    CharClass *new_char = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_char = new(Char, this->value * other->value);
    return (new_char);
}

static CharClass *Char_div(const CharClass *this, const CharClass *other)
{
    CharClass *new_char = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_char = new(Char, this->value / other->value);
    return (new_char);
}

bool Char_eq(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value == other->value);
}

bool Char_gt(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value > other->value);
}

bool Char_lt(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->value < other->value);
}

static const CharClass _description = {
    {
     .__size__ = sizeof(CharClass),
     .__name__ = "Char",
     .__ctor__ = (ctor_t)&Char_ctor,
     .__dtor__ = (dtor_t)&Char_dtor,
     .__str__ = (to_string_t)&Char_str,
     .__add__ = (binary_operator_t)&Char_add,
     .__sub__ = (binary_operator_t)&Char_sub,
     .__mul__ = (binary_operator_t)&Char_mul,
     .__div__ = (binary_operator_t)&Char_div,
     .__eq__ = (binary_comparator_t)&Char_eq,
     .__gt__ = (binary_comparator_t)&Char_gt,
     .__lt__ = (binary_comparator_t)&Char_lt,
    },
    .value = 0
};

const Class *Char = (const Class *)&_description;