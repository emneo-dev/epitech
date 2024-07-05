/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_elem_at_back
*/

#include "double_list.h"

double double_list_get_elem_at_back(double_list_t list)
{
    doublelist_node_t *current = list;

    if (double_list_is_empty(list))
        return 0;
    if (double_list_get_size(list) == 1)
        return double_list_get_elem_at_front(list);
    for (; current->next; current = current->next);
    return current->value;
}