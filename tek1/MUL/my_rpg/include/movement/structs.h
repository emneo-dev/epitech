/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** structs
*/

#ifndef MOVEMENT_STRUCTS_H_
#define MOVEMENT_STRUCTS_H_

#include <SFML/Graphics.h>
#include "rpg.h"

// type is 0 if talk, 1 if map change
typedef struct map_evt_s {
    unsigned char type;
    float radius;
    sfVector2f pos;
    void *evt;
    struct map_evt_s *next;
} map_evt_t;

typedef struct new_map_s {
    sfVector2f start_pos;
    sfVector2f size;
    sfVector2f position;
    char *map_path;
} new_map_t;

typedef struct player_s {
    sfTexture *texture;
    sfVector2f pos;
    sfClock *clock;
    sfIntRect rect;
    inventory_t *inventory;
} player_t;

typedef struct map_s {
    sfVector2f start_pos;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f pos;
    player_t *player;
    map_evt_t *evt;
} map_t;

#endif /* !MOVEMENT_STRUCTS_H_ */
