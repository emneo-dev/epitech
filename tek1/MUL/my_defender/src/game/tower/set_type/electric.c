/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** electric
*/

#include "core.h"

void set_tower_electric(sfTexture *texture, tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->position);
    tower->range = 120.0f;
    tower->type = ELECTRIC;
    tower->level = 1;
    tower->sell_value = 75;
    tower->damages = 6;
    tower->affliction = NONE;
}