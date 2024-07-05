/*
** EPITECH PROJECT, 2021
** vertex
** File description:
** vertex
*/

#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this || !args)
        raise("NULL value given");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (!this)
        raise("NULL value given");
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    if (!this)
        raise("NULL value given");
    ssize_t bufsz = snprintf(
        NULL, 0, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    char* buf = malloc(bufsz + 1);

    if (!buf)
        raise("Out of Memory");
    snprintf(buf, bufsz + 1, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (buf);
}

static VertexClass *Vertex_add(const VertexClass *this, const VertexClass *other)
{
    VertexClass *new_vertex = NULL;

    if (!this || !other)
        raise("NULL value given");

    new_vertex = new(Vertex, this->x + other->x, this->y + other->y, \
        this->z + other->z);
    return (new_vertex);
}

static VertexClass *Vertex_sub(const VertexClass *this, const VertexClass *other)
{
    VertexClass *new_vertex = NULL;

    if (!this || !other)
        raise("NULL value given");

    new_vertex = new(Vertex, this->x - other->x, this->y - other->y, \
        this->z - other->z);
    return (new_vertex);
}

static const VertexClass _description = {
    {
     .__size__ = sizeof(VertexClass),
     .__name__ = "Vertex",
     .__ctor__ = (ctor_t)&Vertex_ctor,
     .__dtor__ = (dtor_t)&Vertex_dtor,
     .__str__ = (to_string_t)&Vertex_str,
     .__add__ = (binary_operator_t)&Vertex_add,
     .__sub__ = (binary_operator_t)&Vertex_sub,
     .__mul__ = NULL,
     .__div__ = NULL,
     .__eq__ = NULL,
     .__gt__ = NULL,
     .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
