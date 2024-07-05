/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_del_elem_at_position
*/

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "double_list.h"

bool double_list_del_elem_at_position(double_list_t *front_ptr,
                                        unsigned int position)
{
    doublelist_node_t *current = *front_ptr;
    doublelist_node_t *previous = *front_ptr;

    if (double_list_is_empty(*front_ptr) ||
        double_list_get_size(*front_ptr) <= position)
        return false;
    if (double_list_get_size(*front_ptr) == 1 || !position)
        return double_list_del_elem_at_front(front_ptr);
    for (uint32_t i = 0; i < position; previous = current,
        current = current->next, i++);
    previous->next = current->next;
    free(current);
    return true;
}