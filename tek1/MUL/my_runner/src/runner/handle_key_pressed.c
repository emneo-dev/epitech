/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** handle_key_pressed
*/

#include "my_runner.h"

void handle_key_pressed(game_object_t *objects)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        sound_jump(objects);
        objects->player->speed = JUMP_FORCE;
    }
}