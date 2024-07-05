/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** handle_events
*/

#include <SFML/Graphics.h>
#include "my_runner.h"

void handle_events(game_object_t *objects)
{
    sfEvent event;

    display_objects(objects);
    while (sfRenderWindow_pollEvent(objects->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(objects->window);
        else if (event.type == sfEvtKeyPressed)
            handle_key_pressed(objects);
    }
    if (check_collisions(objects)) {
        final_screen(objects);
        sfRenderWindow_close(objects->window);
    }
    if (sfSprite_getPosition(objects->player->sprite).y >= 648) {
        final_screen(objects);
        sfRenderWindow_close(objects->window);
    }
}