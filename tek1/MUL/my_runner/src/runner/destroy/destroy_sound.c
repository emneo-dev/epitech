/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** destroy_sound
*/

#include "my_runner.h"

void destroy_sound(game_object_t *objects)
{
    sfSound_stop(objects->jump);
    sfMusic_stop(objects->music);

    sfSoundBuffer_destroy(objects->jump_buff);
    sfSound_destroy(objects->jump);
    sfMusic_destroy(objects->music);
}