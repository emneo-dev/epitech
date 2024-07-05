/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** display_map
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_runner.h"

void display_map(game_object_t *objects)
{
    map_t *current = objects->map;

    for (; current; current = current->next) {
        sfSprite_move(current->top, (sfVector2f) {-SPEED_SCROLL, 0});
        sfSprite_move(current->bottom, (sfVector2f) {-SPEED_SCROLL, 0});
        sfRenderWindow_drawSprite(objects->window, current->top, NULL);
        sfRenderWindow_drawSprite(objects->window, current->bottom, NULL);
    }
}