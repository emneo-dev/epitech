/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** prototypes
*/

#ifndef MOVEMENT_PROTOTYPES_H_
#define MOVEMENT_PROTOTYPES_H_

#include "movement/structs.h"

// Display
int display_map(map_t *map, sfRenderWindow *window);

// Init
int init_player(player_t *player, char const *path, inventory_t *inventory);
int init_map(map_t *map, new_map_t *new_map, player_t *player);
void add_event_node(map_t *map, map_evt_t evt);

#endif /* !MOVEMENT_PROTOTYPES_H_ */
