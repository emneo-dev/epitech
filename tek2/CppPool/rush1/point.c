/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this || !args)
        raise("NULL value given");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (!this)
        raise("NULL value given");
    (void)this;
}

static char *Point_str(PointClass *this)
{
    ssize_t bufsz = 0;
    char* buf = NULL;

    if (!this)
        raise("NULL value given");
    bufsz = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y);
    buf = malloc(bufsz + 1);
    if (!buf)
        raise("Out of Memory");
    snprintf(buf, bufsz + 1, "<Point (%d, %d)>", this->x, this->y);
    return (buf);
}

static PointClass *Point_add(const PointClass *this, const PointClass *other)
{
    PointClass *new_point = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_point = new(Point, this->x + other->x, this->y + other->y);
    return (new_point);
}

static PointClass *Point_sub(const PointClass *this, const PointClass *other)
{
    PointClass *new_point = NULL;

    if (!this || !other)
        raise("NULL value given");
    new_point = new(Point, this->x - other->x, this->y - other->y);
    return (new_point);
}

static const PointClass _description = {
    {
     .__size__ = sizeof(PointClass),
     .__name__ = "Point",
     .__ctor__ = (ctor_t)&Point_ctor,
     .__dtor__ = (dtor_t)&Point_dtor,
     .__str__ = (to_string_t)&Point_str,
     .__add__ = (binary_operator_t)&Point_add,
     .__sub__ = (binary_operator_t)&Point_sub,
     .__mul__ = NULL,
     .__div__ = NULL,
     .__eq__ = NULL,
     .__gt__ = NULL,
     .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
