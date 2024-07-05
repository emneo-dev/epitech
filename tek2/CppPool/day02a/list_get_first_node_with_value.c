/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_get_first_node_with_value
*/

#include <stddef.h>

#include "generic_list.h"

node_t *list_get_first_node_with_value(list_t list, void *value,
    value_comparator_t val_comp)
{
    node_t *current = list;

    if (list_is_empty(list))
        return NULL;
    for (; current->next && val_comp(value, current->value);
        current = current->next);
    if (!val_comp(value, current->value))
        return current;
    return NULL;
}