/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** display_score
*/

#include "my_runner.h"

void display_score(game_object_t *objects)
{
    sfTime time = sfClock_getElapsedTime(objects->g_clock);
    sfText_setString(objects->score,
        int_to_string((long long int) sfTime_asMicroseconds(time)));
    sfRenderWindow_drawText(objects->window, objects->score, NULL);
}