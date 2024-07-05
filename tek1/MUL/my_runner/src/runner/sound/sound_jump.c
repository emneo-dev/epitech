/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** sound_jump
*/

#include <SFML/Audio.h>
#include "corn.h"
#include "my_runner.h"

void sound_jump(game_object_t *objects)
{
    sfSound_stop(objects->jump);
    sfSound_play(objects->jump);
}