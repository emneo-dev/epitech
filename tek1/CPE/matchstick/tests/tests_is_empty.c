/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** tests_is_empty
*/

#include <criterion/criterion.h>
#include "ms.h"

Test(is_empty, empty, .timeout = 1)
{
    map_t *map = NULL;

    map = get_map("5", "5");
    if (!map)
        cr_assert(0);
    map->match[0] = 0;
    map->match[1] = 0;
    map->match[2] = 0;
    map->match[3] = 0;
    map->match[4] = 0;
    cr_expect_eq(is_empty(map), 1);
}

Test(is_empty, not_empty, .timeout = 1)
{
    map_t *map = NULL;

    map = get_map("5", "5");
    if (!map)
        cr_assert(0);
    cr_expect_eq(is_empty(map), 0);
}

Test(is_empty, last_empty, .timeout = 1)
{
    map_t *map = NULL;

    map = get_map("5", "5");
    if (!map)
        cr_assert(0);
    map->match[4] = 0;
    cr_expect_eq(is_empty(map), 0);
}

Test(is_empty, first_empty, .timeout = 1)
{
    map_t *map = NULL;

    map = get_map("5", "5");
    if (!map)
        cr_assert(0);
    map->match[0] = 0;
    cr_expect_eq(is_empty(map), 0);
}