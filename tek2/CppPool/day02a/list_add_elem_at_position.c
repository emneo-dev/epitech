/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_del_elem_at_position
*/

#include <stdint.h>
#include <stdlib.h>

#include "generic_list.h"

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
                                        unsigned int position)
{
    node_t *new_node = NULL;
    node_t *current = *front_ptr;

    if (position > list_get_size(*front_ptr))
        return false;
    if (!(new_node = malloc(sizeof(node_t))))
        return false;
    if (!position)
        return list_add_elem_at_front(front_ptr, elem);
    for (uint32_t i = 0; i < position - 1; i++, current = current->next);
    new_node->value = elem;
    new_node->next = current->next;
    current->next = new_node;
    return true;
}