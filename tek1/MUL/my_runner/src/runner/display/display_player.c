/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** display_player
*/

#include "my_runner.h"
#include "corn.h"

void display_player(game_object_t *objects)
{
    sfSprite_setTextureRect(objects->player->sprite, objects->player->rect);
    sfSprite_setScale(objects->player->sprite, (sfVector2f) {0.2, 0.2});
    apply_gravity(objects->player, 20);
    sfSprite_move(objects->player->sprite,
                (sfVector2f) {0, objects->player->speed});
    sfRenderWindow_drawSprite(objects->window, objects->player->sprite, NULL);
    if (corn_check_clock(objects->player->clock, 0.15f, sfTrue))
        corn_move_rect(&objects->player->rect, 443, 443);
}