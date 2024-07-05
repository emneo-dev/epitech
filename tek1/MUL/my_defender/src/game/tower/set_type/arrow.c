/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** bomb
*/

#include "tower.h"

void set_tower_arrow(sfTexture *texture, tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->position);
    tower->range = 230.0f;
    tower->type = NORMAL;
    tower->speed = 1.2f;
    tower->level = 1;
    tower->damages = 20;
    tower->sell_value = 100;
    tower->affliction = NONE;
}