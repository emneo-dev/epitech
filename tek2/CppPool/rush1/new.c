/*
** EPITECH PROJECT, 2021
** new
** File description:
** new
*/

#include "player.h"
#include "new.h"

void delete(Object *ptr)
{
    Class *class = (Class *)ptr;

    if (!ptr)
        raise("NULL value given");
    if (class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *new = NULL;

    if (!class)
        raise("A class wasn't provided");
    new = malloc(class->__size__);
    if (!new)
        raise("Out of Memory");
    memcpy(new, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new, ap);
    return (new);
}

Object *new (const Class *class, ...)
{
    Object *new = NULL;
    va_list va;

    va_start(va, class);
    new = va_new(class, &va);
    va_end(va);
    return (new);
}