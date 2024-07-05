/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** ai
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "ms.h"
#include "my.h"

static void random_ai(map_t *map)
{
    int i = 0;
    int max = 0;
    unsigned char to_get = 0;

    for (i = 0; !map->match[i]; ++i);
    max = (map->match[i] > map->max_match) ? map->max_match : map->match[i];
    srandom(time(NULL));
    to_get = (map->match[i] == 1) ? 1 :
        (unsigned char) (random() % (max - 1) + 1);
    my_putstr("\nAI's turn...\nAI removed ");
    my_put_nbr(to_get);
    my_putstr(" match(es) from line ");
    my_put_nbr(i + 1);
    write(1, "\n", 1);
    map->match[i] -= to_get;
}

static int count_all_matches(map_t *map)
{
    int matches = 0;

    for (int i = 0; i < map->size; ++i)
        matches += map->match[i];
    return (matches);
}

static int will_be_empty(int match, int line, map_t *map)
{
    int empty = 0;

    map->match[line] -= match;
    empty = is_empty(map);
    map->match[line] += match;
    return (empty);
}

static int do_a_move(map_t *map, int i)
{
    int z = (map->match[i] > map->max_match) ? map->max_match : map->match[i];

    for (; z > 0; z--) {
        if (((z ^ (map->match[i] ^ calculate_sum(map))) != 0 &&
            !will_be_empty(z, i, map) &&
            ((count_all_matches(map) - z > map->max_match + 1) ||
            count_all_matches(map) <= 5)) ||
            (z == 1 && will_be_empty(z, i, map))) {
            my_putstr("\nAI's turn...\nAI removed ");
            my_put_nbr(z);
            my_putstr(" match(es) from line ");
            my_put_nbr(i + 1);
            write(1, "\n", 1);
            map->match[i] -= z;
            return (1);
        }
    }
    return (0);
}

void ai(map_t *map)
{
    for (int i = 0; i < map->size; i++)
        if (do_a_move(map, i))
            return;
    random_ai(map);
}