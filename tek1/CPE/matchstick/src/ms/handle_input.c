/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** handle_input
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "ms.h"

static int update_map(map_t *map, long long int line, long long int matches)
{
    if (matches > map->max_match) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(5);
        my_putstr(" matches per turn");
        return (handle_input(map));
    }
    else if (matches > map->match[line - 1]) {
        my_putstr("Error: not enough matches on this line");
        return (handle_input(map));
    }
    else if (matches <= 0) {
        my_putstr("Error: you have to remove at least one match");
        return (handle_input(map));
    }
    map->match[line - 1] -= matches;
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    write(1, "\n", 1);
    return (1);
}

static int out_of_range(map_t *map)
{
    my_putstr("Error: this line is out of range");
    return (handle_input(map));
}

static int not_number(map_t *map)
{
    my_putstr("Error: invalid input (positive number expected)");
    return (handle_input(map));
}

static long long int get_input_nbr(void)
{
    long long int nb = 0;
    char *line = NULL;
    size_t read_size = 0;
    int return_line = 0;

    return_line = getline(&line, &read_size, stdin);
    if (return_line == -1)
        return (-1);
    r_carriage(line);
    if (!my_str_isnum(line))
        return (-2);
    nb = my_getnbr(line);
    return (nb);
}

int handle_input(map_t *map)
{
    long long int nb_line = 0;
    long long int nb_match = 0;

    my_putstr("\nLine: ");
    nb_line = get_input_nbr();
    if (nb_line == -1)
        return (0);
    else if (nb_line == -2)
        return (not_number(map));
    if (nb_line > map->size || nb_line < 1)
        return (out_of_range(map));
    my_putstr("Matches: ");
    nb_match = get_input_nbr();
    if (nb_match == -1)
        return (0);
    else if (nb_match == -2)
        return (not_number(map));
    return (update_map(map, nb_line, nb_match));
}