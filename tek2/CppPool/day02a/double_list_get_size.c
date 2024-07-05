/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_size
*/

#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int size = 0;

    if (!list)
        return 0;
    for (; list; list = list->next, size++);
    return size;
}