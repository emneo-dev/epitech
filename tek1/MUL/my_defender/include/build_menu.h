/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** build_menu
*/

#ifndef BUILD_MENU_H_
#define BUILD_MENU_H_

#include <SFML/Graphics.h>

enum build_menu_status {
    CLOSED = 0,
    OPENING = 1,
    OPENED = 2,
    CLOSING = 3,
};

typedef struct build_menu_s {
    int status;
    sfSprite *bomb;
    sfSprite *fire;
    sfSprite *ice;
    sfSprite *thunder;
    sfSprite *arrow;
    sfSprite *sell;
    sfSprite *upgrade;
    sfVector2f scale;
}b_menu_t;

#endif /* !BUILD_MENU_H_ */