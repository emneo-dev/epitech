/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_add_elem_at_front
*/

#include <stdlib.h>

#include "generic_list.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}