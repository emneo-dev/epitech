/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** tests_destroy_map
*/

#include <criterion/criterion.h>
#include "ms.h"

Test(destroy_map, normal_8_size_destroy, .timeout = 1)
{
    map_t *map = get_map("8", "3");
    destroy_map(map);
}