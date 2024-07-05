/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** key_cmp_container
*/

#include <stddef.h>

#include "map.h"

key_comparator_t key_cmp_container(bool store, key_comparator_t new_key_cmp)
{
    static key_comparator_t key_cmp = NULL;

    if (store)
        key_cmp = new_key_cmp;
    return key_cmp;
}