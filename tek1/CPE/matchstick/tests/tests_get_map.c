/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** tests_get_map
*/

#include <criterion/criterion.h>
#include <my.h>
#include "ms.h"

Test(get_map, normal_8_size, .timeout = 1)
{
    map_t *map = get_map("8", "1");

    cr_expect_eq(map->match[0], 1);
    cr_expect_eq(map->match[1], 3);
    cr_expect_eq(map->match[2], 5);
    cr_expect_eq(map->match[3], 7);
    cr_expect_eq(map->match[4], 9);
    cr_expect_eq(map->match[5], 11);
    cr_expect_eq(map->match[6], 13);
    cr_expect_eq(map->match[7], 15);
    cr_expect_eq(map->size, 8);
}

Test(get_map, normal_8_size_with_0_max_match, .timeout = 1)
{
    map_t *map = get_map("8", "0");

    cr_expect_eq(map, NULL);
}

Test(get_map, overflow_size, .timeout = 1)
{
    map_t *map = get_map("234567876543", "3");

    cr_expect_eq(map, NULL);
}

Test(get_map, negative_size, .timeout = 1)
{
    map_t *map = get_map("-30", "42");

    cr_expect_eq(map, NULL);
}