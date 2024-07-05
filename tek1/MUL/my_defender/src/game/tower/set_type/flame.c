/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** flame
*/

#include "tower.h"

void set_tower_flame(sfTexture *texture, tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->position);
    tower->range = 180.0f;
    tower->type = FIRE;
    tower->level = 1;
    tower->sell_value = 75;
    tower->damages = 15;
    tower->affliction = BURN;
}