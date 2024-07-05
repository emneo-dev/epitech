/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init
*/

#include <stdlib.h>
#include "cg.h"
#include "core.h"
#include "my.h"

void init_player(t_list_t *list, player_t *player)
{
    player->health = 10;
    player->money = 500;
    player->stat_font = sfFont_createFromFile("res/font/money.ttf");
    player->bal_str = my_itoa(player->money);
    player->bal_text = cg_create_text(player->bal_str, 50,
    player->stat_font, sfYellow);
    sfText_setPosition(player->bal_text, (sfVector2f){60, 0});
    player->coin = cg_load_sprite_form_file(NULL, &list->coin);
    sfSprite_setPosition(player->coin, (sfVector2f){3, 5});
}
