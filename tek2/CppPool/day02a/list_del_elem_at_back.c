/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_del_elem_at_back
*/

#include <stdlib.h>

#include "generic_list.h"

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *current = *front_ptr;
    node_t *previous = *front_ptr;

    if (list_is_empty(*front_ptr))
        return false;
    if (list_get_size(*front_ptr) == 1)
        return list_del_elem_at_front(front_ptr);
    for (; current->next; previous = current, current = current->next);
    free(current);
    previous->next = NULL;
    return true;
}