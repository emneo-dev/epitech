/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_del_elem_at_front
*/

#include <stdlib.h>

#include "double_list.h"

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    doublelist_node_t *current = *front_ptr;

    if (double_list_is_empty(*front_ptr))
        return false;
    *front_ptr = current->next;
    free(current);
    return true;
}