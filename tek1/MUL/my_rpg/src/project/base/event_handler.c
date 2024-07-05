/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_handler
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void base_event_handler(core_t *core)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(core->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(core->window);
}