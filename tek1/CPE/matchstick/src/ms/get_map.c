/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** get_map
*/

#include <unistd.h>
#include "ms.h"
#include "my.h"

static unsigned char *init_map(short size)
{
    unsigned char *match = NULL;

    match = malloc(sizeof(unsigned char) * size);
    if (!match)
        return (NULL);
    for (unsigned char i = 0; i < size; i++)
        match[i] = i * 2 + 1;
    return (match);
}

map_t *get_map(char *size, char *max_match)
{
    map_t *map = NULL;
    int size_n = 0;
    int max_match_tmp = 0;

    map = malloc(sizeof(map_t));
    if (map == NULL)
        return (NULL);
    size_n = my_getnbr(size);
    if (!size_n || !(size_n > 1 && size_n < 100))
        return (NULL);
    map->size = (unsigned char) size_n;
    map->match = init_map(map->size);
    if (!map->match)
        return (NULL);
    max_match_tmp = my_getnbr(max_match);
    if (max_match_tmp <= 0)
        return (NULL);
    map->max_match = max_match_tmp;
    return (map);
}