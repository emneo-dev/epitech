/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** none
*/

#include "core.h"
#include "functions.h"

void sell_tower(sfTexture *texture, tower_t *tower, player_t *player)
{
    sfSprite_destroy(tower->sprite);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->position);
    tower->affliction = NONE;
    tower->damages = 0;
    tower->level = 0;
    tower->range = 0;
    change_coin(player, tower->sell_value);
    tower->sell_value = 0;
    tower->type = NONE;
}