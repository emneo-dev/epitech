/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** close
*/

#include "build_menu.h"

void close_build_menu(b_menu_t *menu)
{
    menu->scale.x -= 0.1f;
    menu->scale.y -= 0.1f;

    sfSprite_setScale(menu->bomb, menu->scale);
    sfSprite_setScale(menu->fire, menu->scale);
    sfSprite_setScale(menu->ice, menu->scale);
    sfSprite_setScale(menu->thunder, menu->scale);
    if (menu->scale.x <= 0)
        menu->status = CLOSED;
}