/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** display_objects
*/

#include "my_runner.h"

void display_objects(game_object_t *objects)
{
    display_parralax(objects, 0.5);
    display_map(objects);
    display_player(objects);
    display_score(objects);
}