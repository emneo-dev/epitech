/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** create_button
*/

#include <stdlib.h>
#include "tower.h"

tower_t *create_button(tower_t *list, sfVector2f pos, sfTexture *texture)
{
    tower_t *new = malloc(sizeof(tower_t));
    tower_t *last = list;

    if (new == NULL)
        return (NULL);
    new->level = 0;
    new->next = 0;
    new->position = pos;
    new->range = 0;
    new->rect = (sfIntRect){0, 0, 50, 50};
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, texture, sfFalse);
    sfSprite_setPosition(new->sprite, new->position);
    new->type = NONE;
    new->attack = sfClock_create();
    new->speed = 0;
    if (list == NULL)
        return (new);
    for (; last->next != NULL; last = last->next);
    last->next = new;
    return (new);
}