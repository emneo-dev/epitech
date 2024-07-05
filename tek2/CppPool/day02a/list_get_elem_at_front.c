/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_elem_at_front
*/

#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    node_t *current = list;

    if (list_is_empty(list))
        return 0;
    return current->value;
}