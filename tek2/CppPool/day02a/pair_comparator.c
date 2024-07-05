/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** pair_comparator
*/

#include <stddef.h>

#include "map.h"

int pair_comparator(void *first, void *second)
{
    key_comparator_t key_cmp = key_cmp_container(false, NULL);

    return key_cmp(first, second);
}