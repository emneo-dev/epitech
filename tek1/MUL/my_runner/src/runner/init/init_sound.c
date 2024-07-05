/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** init_sound
*/

#include "corn.h"
#include "my_runner.h"

void init_sound(game_object_t *objects)
{
    objects->jump = NULL;
    objects->music = NULL;
    objects->jump_buff = NULL;

    objects->music = corn_load_sound(MUS_F, 60, 1);
    sfMusic_setLoop(objects->music, 1);
    sfMusic_play(objects->music);
    objects->jump_buff = sfSoundBuffer_createFromFile(JMP_F);
    objects->jump = sfSound_create();
    sfSound_setBuffer(objects->jump, objects->jump_buff);
    sfSound_setVolume(objects->jump, 15);
}