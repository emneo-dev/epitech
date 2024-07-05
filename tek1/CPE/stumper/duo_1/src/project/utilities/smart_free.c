/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** smart_free.c
*/

#include <stdlib.h>

void smart_free(void *ptr)
{
    ptr ? free(ptr) : NULL;
}
