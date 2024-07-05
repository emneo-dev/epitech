/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** entry_point
*/

#include "my.h"
#include "ms.h"

int entry_point(map_t *map)
{
    my_putstr("\nYour turn:");
    return (handle_input(map));
}