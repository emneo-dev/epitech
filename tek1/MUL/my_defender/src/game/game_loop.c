/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** game_loop
*/

#include <stdlib.h>
#include "core.h"
#include "functions.h"
#include "cg.h"
#include "my.h"

void start_new_wave(core_t *core)
{
    core->data.status = RUNNING;
    core->data.next_spawn =
    (float)rand()/(float)(RAND_MAX) * 3.0f + 0.4f;
    core->data.enemy_left = 5 + (rand() % core->data.wave * 1.3f);
    free(core->wave_stock);
    sfText_setPosition(core->wave_text, (sfVector2f){-300, 720 / 2 - 120});
    core->wave_stock = NULL;
}

void intermission_animation(core_t *core)
{
    char *nb_stock;
    sfVector2f text_pos;

    if (!core->wave_stock) {
        core->data.wave += 1;
        nb_stock = my_itoa(core->data.wave);
        core->wave_stock = my_append("wave ", nb_stock);
        free(nb_stock);
        sfText_setString(core->wave_text, core->wave_stock);
    }
    sfText_move(core->wave_text, (sfVector2f){5, 0});
    text_pos = sfText_getPosition(core->wave_text);
    if (text_pos.x >= 1500)
        start_new_wave(core);
}

void game_loop(core_t *core, sfRenderWindow *w)
{
    draw_game(core, w);
    event_handler(core, w);
    if (core->clicked != NULL) {
        open_build_menu(core->clicked, &core->build_menu);
    } else if (core->build_menu.status == CLOSING)
        close_build_menu(&core->build_menu);
    core->enemy = follow_path(core->enemy, &core->player.health);
    tower_attack(core, core->enemy, &core->player);
    if (core->enemy == NULL && core->data.status == RUNNING)
        core->data.status = INTERMISSION;
    if (core->data.status == INTERMISSION)
        intermission_animation(core);
    if (core->data.enemy_left > 0 && core->data.status == RUNNING &&
    cg_check_clock(core->spawn, core->data.next_spawn, sfTrue)) {
        core->enemy = init_enemy(core);
        core->data.enemy_left -= 1;
    }
}
