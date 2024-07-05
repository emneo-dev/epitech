/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** enemy
*/

#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.h>

struct path {
    sfVector2f pos;
    struct path *next;
};

typedef struct enemy_s {
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    sfFloatRect gbound;
    int health;
    float speed;
    int anim_cycle;
    int value;
    struct path *path;
    struct enemy_s *next;
}enemy_t;

#endif /* !ENEMY_H_ */