/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** calculate_sum
*/

#include "ms.h"

int calculate_sum(map_t *map)
{
    int sum = map->match[0];

    for (int i = 1; i < map->size; i++)
        sum = sum ^ map->match[i];
    return (sum);
}