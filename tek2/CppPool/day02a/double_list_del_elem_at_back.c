/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_del_elem_at_back
*/

#include <stdlib.h>

#include "double_list.h"

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    doublelist_node_t *current = *front_ptr;
    doublelist_node_t *previous = *front_ptr;

    if (double_list_is_empty(*front_ptr))
        return false;
    if (double_list_get_size(*front_ptr) == 1)
        return double_list_del_elem_at_front(front_ptr);
    for (; current->next; previous = current, current = current->next);
    free(current);
    previous->next = NULL;
    return true;
}