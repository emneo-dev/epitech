/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** map_del_elem
*/

#include <stdint.h>

#include "map.h"

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    node_t *current = *map_ptr;

    if (list_is_empty(*map_ptr))
        return false;
    for (uint32_t i = 0; current; current = current->next, i++)
        if (!key_cmp(((pair_t *) current->value)->key, key))
            return list_del_elem_at_position(map_ptr, i);
    return false;
}