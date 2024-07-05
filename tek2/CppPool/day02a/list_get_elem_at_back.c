/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_elem_at_back
*/

#include "generic_list.h"

void *list_get_elem_at_back(list_t list)
{
    node_t *current = list;

    if (list_is_empty(list))
        return 0;
    if (list_get_size(list) == 1)
        return list_get_elem_at_front(list);
    for (; current->next; current = current->next);
    return current->value;
}