/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_first_node_with_value
*/

#include <stddef.h>

#include "double_list.h"

doublelist_node_t  *double_list_get_first_node_with_value(double_list_t list,
                                                        double value)
{
    doublelist_node_t *current = list;

    if (double_list_is_empty(list))
        return NULL;
    for (; current->next && !(current->value == value);
        current = current->next);
    if (current->value == value)
        return current;
    return NULL;
}