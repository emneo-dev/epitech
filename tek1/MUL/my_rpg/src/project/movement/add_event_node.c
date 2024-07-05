/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** add_event_node
*/

#include <stdlib.h>
#include "utility.h"
#include "movement/structs.h"

static map_evt_t *init_evt(map_t *map, map_evt_t evt)
{
    map_evt_t *new_evt = NULL;

    new_evt = malloc(sizeof(map_evt_t));
    if (!new_evt) {
        my_puterr("Could not add event node to map! (malloc failure)");
        return (NULL);
    }
    new_evt->evt = evt.evt;
    new_evt->type = evt.type;
    new_evt->pos = evt.pos;
    new_evt->radius = evt.radius;
    new_evt->next = map->evt;
    return (new_evt);
}

void add_event_node(map_t *map, map_evt_t evt)
{
    map_evt_t *new_evt = NULL;

    if (!map) {
        my_puterr("Could not add event node to map! (map or evt NULL)");
        return;
    }
    new_evt = init_evt(map, evt);
    if (!new_evt)
        return;
    map->evt = new_evt;
}