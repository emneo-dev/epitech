/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** destroy_score
*/

#include "my_runner.h"

void destroy_score(game_object_t *objects)
{
    sfText_destroy(objects->score);
    sfFont_destroy(objects->my_font);
    sfClock_destroy(objects->g_clock);
}