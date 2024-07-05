/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** check_tower_click
*/

#include "core.h"

tower_t *check_tower_click(tower_t *t, sfVector2i mouse)
{
    for (; t != NULL; t = t->next)
        if (mouse.x >= t->position.x && mouse.x <= t->position.x + 50 &&
        mouse.y >= t->position.y && mouse.y <= t->position.y + 50)
            break;
    if (t == NULL)
        return (NULL);
    return (t);
}