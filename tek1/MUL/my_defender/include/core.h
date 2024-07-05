/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** core
*/

#ifndef CORE_H_
#define CORE_H_

#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include "tower.h"
#include "player.h"
#include "menu.h"
#include "build_menu.h"
#include "enemy.h"

enum wave_status {
    INTERMISSION = 0,
    RUNNING = 1,
};

typedef struct texture_list_s {
    sfTexture *build_button;
    sfTexture *bomb;
    sfTexture *tower_bomb;
    sfTexture *ice;
    sfTexture *tower_ice;
    sfTexture *fire;
    sfTexture *tower_fire;
    sfTexture *thunder;
    sfTexture *tower_elec;
    sfTexture *arrow;
    sfTexture *tower_arrow;
    sfTexture *knight;
    sfTexture *sell;
    sfTexture *upgrade;
    sfTexture *coin;
    sfTexture *map;
} t_list_t;

typedef struct core_var_s {
    float next_spawn;
    int wave;
    int enemy_left;
    int status;
} core_var_t;

typedef struct core_s {
    tower_t *towers;
    tower_t *clicked;
    sfCircleShape *tow_range;
    b_menu_t build_menu;
    t_list_t t_list;
    player_t player;
    enemy_t *enemy;
    sfSprite *map;
    sfClock *clock;
    sfClock *spawn;
    sfMusic *ambient;
    core_var_t data;
    sfText *wave_text;
    char *wave_stock;
    sfRenderWindow *window;
} core_t;

#endif /* !CORE_H_ */
