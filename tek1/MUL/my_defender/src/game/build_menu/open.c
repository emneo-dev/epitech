/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** open_build_menu
*/

#include "core.h"

void place_b_menu_button(sfVector2f pos, sfSprite *sprite, int x, int y)
{
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, (sfVector2f){0, 0});
    sfSprite_move(sprite, (sfVector2f){x, y});
}

void b_menu_animation(sfVector2f scale, sfSprite *sprite, sfVector2f move)
{
    sfSprite_setScale(sprite, scale);
    sfSprite_move(sprite, move);
}

void do_open_animation(b_menu_t *menu, tower_t *selected)
{
    menu->scale.x += 0.1f;
    menu->scale.y += 0.1f;
    if (selected->type == NONE) {
        b_menu_animation(menu->scale, menu->bomb, (sfVector2f){10, -10});
        b_menu_animation(menu->scale, menu->fire, (sfVector2f){-10, -10});
        b_menu_animation(menu->scale, menu->ice, (sfVector2f){-10, 10});
        b_menu_animation(menu->scale, menu->thunder, (sfVector2f){10, 10});
        b_menu_animation(menu->scale, menu->arrow, (sfVector2f){0, 15});
    } else {
        b_menu_animation(menu->scale, menu->sell, (sfVector2f){-10, -10});
        b_menu_animation(menu->scale, menu->upgrade, (sfVector2f){10, 10});
    }
    menu->status = (menu->scale.x) >= 1.0f ? OPENED : OPENING;
}

void open_build_menu(tower_t *selected, b_menu_t *menu)
{
    if (menu->status == CLOSED) {
        if (selected->type == NONE) {
            place_b_menu_button(selected->position, menu->bomb, -100, 0);
            place_b_menu_button(selected->position, menu->fire, 0, 100);
            place_b_menu_button(selected->position, menu->ice, 100, 0);
            place_b_menu_button(selected->position, menu->thunder, 0, -100);
            place_b_menu_button(selected->position, menu->arrow, 75, -75);
        } else {
            place_b_menu_button(selected->position, menu->sell, 0, 100);
            place_b_menu_button(selected->position, menu->upgrade, 0, -100);
        }
        menu->scale = (sfVector2f){0, 0};
        menu->status = OPENING;
    } else if (menu->status == OPENING)
        do_open_animation(menu, selected);
}