/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_elem_at_position
*/

#include <stdint.h>

#include "generic_list.h"

void *list_get_elem_at_position(list_t list,
                                        unsigned int position)
{
    node_t *current = list;

    if (list_is_empty(list) || list_get_size(list) <= position)
        return 0;
    if (list_get_size(list) == 1 || !position)
        return list_get_elem_at_front(list);
    for (uint32_t i = 0; i < position; current = current->next, i++);
    return current->value;
}