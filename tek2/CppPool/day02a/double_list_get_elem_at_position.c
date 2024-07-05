/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_elem_at_position
*/

#include <stdint.h>

#include "double_list.h"

double double_list_get_elem_at_position(double_list_t list,
                                        unsigned int position)
{
    doublelist_node_t *current = list;

    if (double_list_is_empty(list) || double_list_get_size(list) <= position)
        return 0;
    if (double_list_get_size(list) == 1 || !position)
        return double_list_get_elem_at_front(list);
    for (uint32_t i = 0; i < position; current = current->next, i++);
    return current->value;
}