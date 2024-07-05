/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** build menu
*/

#include "build_menu.h"

void clean_build_menu(b_menu_t *menu)
{
    sfSprite_destroy(menu->arrow);
    sfSprite_destroy(menu->bomb);
    sfSprite_destroy(menu->fire);
    sfSprite_destroy(menu->ice);
    sfSprite_destroy(menu->sell);
    sfSprite_destroy(menu->thunder);
    sfSprite_destroy(menu->upgrade);
}