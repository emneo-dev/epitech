/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** destroy_game_objects
*/

#include <stdlib.h>
#include "my_runner.h"

void destroy_game_objects(game_object_t *objects)
{
    destroy_map(objects->map);
    destroy_parralax(objects->parralax);
    destroy_player(objects->player);
    sfRenderWindow_destroy(objects->window);
    destroy_sound(objects);
    destroy_score(objects);
    free(objects);
}