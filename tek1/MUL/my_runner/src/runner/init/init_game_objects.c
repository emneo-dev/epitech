/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** init_game_objects
*/

#include <stdlib.h>
#include <stdio.h>
#include "corn.h"
#include "my_runner.h"

game_object_t *init_game_objects(char const *name)
{
    game_object_t *game_objects = malloc(sizeof(game_object_t));
    if (!game_objects)
        return (NULL);
    game_objects->map = init_map(name);
    if (!game_objects->map)
        return (NULL);
    game_objects->window = init_window(name, (sfVector2u) {1152, 648});
    game_objects->player = init_player();
    if (!game_objects->player)
        return (NULL);
    game_objects->parralax = init_parralax();
    if (!game_objects->parralax)
        return (NULL);
    init_sound(game_objects);
    init_score(game_objects);
    game_objects->is_won = 0;
    return (game_objects);
}