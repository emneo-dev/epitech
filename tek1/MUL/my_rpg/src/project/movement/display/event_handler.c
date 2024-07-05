/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** event_handler
*/

#include <stdio.h>
#include <math.h>
#include "rpg.h"
#include "talk/prototypes.h"
#include "movement/internal.h"
#include "movement/structs.h"

static int is_in_range(map_evt_t *evt, player_t *player)
{
    return (sqrt(pow((evt->pos.x - player->pos.x) / 2, 2) +
            pow((evt->pos.y - player->pos.y) / 2, 2)) < evt->radius);
}

static int special_evt_handler(sfRenderWindow *window,
                               map_t *map)
{
    map_evt_t *evt = map->evt;

    for (; evt; evt = evt->next) {
        if (is_in_range(evt, map->player) && evt->type == 0) {
            launch_talk((talk_t *) evt->evt, window);
            return (0);
        }
        else if (is_in_range(evt, map->player) && evt->type == 1)
            return ((int) (long) evt->evt);
    }
    return (0);
}

static int other_keys(sfRenderWindow *window, map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyE))
        return (display_inventory(map->player->inventory, window));
    return (0);
}

int event_handler(sfRenderWindow *window, map_t *map, sfClock *clock)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        return (special_evt_handler(window, map));
    else if (sfKeyboard_isKeyPressed(sfKeyUp) ||
             sfKeyboard_isKeyPressed(sfKeyDown))
        return (vertical_handler(map, clock));
    else if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
             sfKeyboard_isKeyPressed(sfKeyRight))
        return (horizontal_handler(map, clock));
    return (other_keys(window, map));
}