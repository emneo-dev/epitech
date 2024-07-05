/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_elem_at_front
*/

#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    doublelist_node_t *current = list;

    if (double_list_is_empty(list))
        return 0;
    return current->value;
}