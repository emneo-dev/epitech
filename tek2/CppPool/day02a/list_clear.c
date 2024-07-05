/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion [SSH: 192.168.0.19]
** File description:
** list_clear
*/

#include <stddef.h>

#include "generic_list.h"

void list_clear(list_t *list)
{
    while (!list_is_empty(*list))
        list_del_elem_at_front(list);
    *list = NULL;
}