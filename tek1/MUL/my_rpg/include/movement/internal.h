/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** internal
*/

#ifndef MOVEMENT_INTERNAL_H_
#define MOVEMENT_INTERNAL_H_

#include <SFML/Graphics.h>
#include "movement/structs.h"

int cg_check_clock(sfClock *clock, float time, sfBool restart);
void cg_move_rect(sfIntRect *rect, int move, int maximum);
int event_handler(sfRenderWindow *window, map_t *map, sfClock *clock);
int vertical_handler(map_t *map, sfClock *clock);
int horizontal_handler(map_t *map, sfClock *clock);

#endif /* !MOVEMENT_INTERNAL_H_ */
