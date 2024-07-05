/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_del_elem_at_front
*/

#include <stdlib.h>

#include "generic_list.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    node_t *current = *front_ptr;

    if (list_is_empty(*front_ptr))
        return false;
    *front_ptr = current->next;
    free(current);
    return true;
}