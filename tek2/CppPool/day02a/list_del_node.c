/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** list_del_node
*/

#include <stdint.h>
#include <stddef.h>

#include "generic_list.h"

bool list_del_node(list_t *front_ptr, node_t *node_ptr)
{
    node_t *current = *front_ptr;

    if (list_is_empty(*front_ptr))
        return false;
    for (uint32_t i = 0; current; current = current->next, i++)
        if (current == node_ptr)
            return list_del_elem_at_position(front_ptr, i);
    return false;
}