/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** tower
*/

#ifndef TOWER_H_
#define TOWER_H_

#include <SFML/Graphics.h>
#include "affliction.h"

enum tower_type {
    NONE = 0,
    FIRE = 1,
    EXPLOSIVE = 2,
    ICE = 3,
    ELECTRIC = 4,
    NORMAL = 5,
};

typedef struct tower_s {
    sfSprite *sprite;
    sfVector2f position;
    int type;
    int damages;
    float range;
    float speed;
    int sell_value;
    int level;
    int affliction;
    sfIntRect rect;
    sfClock *attack;
    struct tower_s *next;
}tower_t;

#endif /* !TOWER_H_ */