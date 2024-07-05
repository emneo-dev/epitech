/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** init_map
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "corn.h"
#include "my_runner.h"

static int get_position(char **line)
{
    int nb = 0;

    if (!line)
        return (0);
    if (!(*line))
        return (0);
    for (; **line && **line == ' '; (*line)++);
    for (; **line && **line != '\n' && **line != ' '; nb *= 10, (*line)++)
        nb += (**line) - '0';
    if (nb)
        return (nb / 10);
    return (nb);
}

static int comp_pos(map_t *map)
{
    return (sfSprite_getPosition(map->bottom).x + LEN_OB);
}

static void add_node(map_t **map, sfVector2u positions)
{
    map_t *new = NULL;

    new = malloc(sizeof(map_t));
    new->top = corn_load_sprite_from_file(BUIL, &new->top_tex);
    new->bottom = corn_load_sprite_from_file(BUIL, &new->bottom_tex);
    sfSprite_setRotation(new->top, 180);
    sfSprite_setScale(new->top, (sfVector2f) {1, 4});
    sfSprite_setScale(new->bottom, (sfVector2f) {1, 4});
    if (!(*map)) {
        sfSprite_setPosition(new->top, (sfVector2f) {2095, positions.x});
        sfSprite_setPosition(new->bottom,
                            (sfVector2f) {2000, 648 - positions.y});
    } else {
        sfSprite_setPosition(new->top, (sfVector2f) {comp_pos(*map) + 95,
                            positions.x});
        sfSprite_setPosition(new->bottom, (sfVector2f) {comp_pos(*map),
                            648 - positions.y});
    }
    new->next = *map;
    *map = new;
}

static sfVector2u get_sector(int fd)
{
    char *buffer = NULL;
    sfVector2u tmp = {0, 0};

    buffer = get_next_line(fd);
    tmp.x = get_position(&buffer);
    tmp.y = get_position(&buffer);
    return (tmp);
}

map_t *init_map(char const *filepath)
{
    int fd = 0;
    sfVector2u tmp = {0, 0};
    map_t *map = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (NULL);
    while (1) {
        tmp = get_sector(fd);
        if (!tmp.x && !tmp.y) {
            add_node(&map, tmp);
            close(fd);
            return (map);
        }
        add_node(&map, tmp);
    }
    return (NULL);
}