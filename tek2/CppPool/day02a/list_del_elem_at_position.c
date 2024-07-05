/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_del_elem_at_position
*/

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "generic_list.h"

bool list_del_elem_at_position(list_t *front_ptr,
                                        unsigned int position)
{
    node_t *current = *front_ptr;
    node_t *previous = *front_ptr;

    if (list_is_empty(*front_ptr) ||
        list_get_size(*front_ptr) <= position)
        return false;
    if (list_get_size(*front_ptr) == 1 || !position)
        return list_del_elem_at_front(front_ptr);
    for (uint32_t i = 0; i < position; previous = current,
        current = current->next, i++);
    previous->next = current->next;
    free(current);
    return true;
}