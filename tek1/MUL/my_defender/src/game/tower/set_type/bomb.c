/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** bomb
*/

#include "tower.h"

void set_tower_bomb(sfTexture *texture, tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->position);
    tower->range = 150.0f;
    tower->type = EXPLOSIVE;
    tower->level = 1;
    tower->damages = 10;
    tower->sell_value = 120;
    tower->affliction = NONE;
}