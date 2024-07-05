/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_path
*/

#include <stdlib.h>
#include "enemy.h"

struct path *add_path_point(struct path *list, sfVector2f point)
{
    struct path *last = list;

    struct path *new = malloc(sizeof(struct path));

    for (; last != NULL && last->next != NULL; last = last->next);
    new->pos = point;
    new->next = NULL;
    if (!last)
        return (new);
    last->next = new;
    return (list);
}

struct path *set_enemy_path(void)
{
    struct path *path = NULL;

    path = add_path_point(path, (sfVector2f){219, 520});
    add_path_point(path, (sfVector2f){200, 280});
    add_path_point(path, (sfVector2f){450, 280});
    add_path_point(path, (sfVector2f){450, 470});
    add_path_point(path, (sfVector2f){620, 470});
    add_path_point(path, (sfVector2f){620, 580});
    add_path_point(path, (sfVector2f){980, 580});
    add_path_point(path, (sfVector2f){980, 200});
    return (path);
}