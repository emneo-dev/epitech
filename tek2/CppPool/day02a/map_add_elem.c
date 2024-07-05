/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** map_add_elem
*/

#include <stdlib.h>

#include "map.h"

bool map_add_elem(map_t *map_ptr, void *key, void *value,
    key_comparator_t key_cmp)
{
    pair_t *new_key_value = malloc(sizeof(pair_t));

    new_key_value->key = key;
    new_key_value->value = value;
    map_del_elem(map_ptr, key, key_cmp);
    return list_add_elem_at_front(map_ptr, new_key_value);
}