/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_size
*/

#include "generic_list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int size = 0;

    if (!list)
        return 0;
    for (; list; list = list->next, size++);
    return size;
}