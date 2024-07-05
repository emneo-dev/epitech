/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** map_get_elem
*/

#include <stddef.h>
#include <stdint.h>

#include "map.h"

void *map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    node_t *current = map;

    if (list_is_empty(map))
        return NULL;
    for (uint32_t i = 0; current; current = current->next, i++)
        if (!key_cmp(((pair_t *) current->value)->key, key))
            return ((pair_t *) (current->value))->value;
    return NULL;
}