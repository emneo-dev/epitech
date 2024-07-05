/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** map_is_empty
*/

#include "map.h"

bool map_is_empty(map_t map)
{
    return list_is_empty(map);
}