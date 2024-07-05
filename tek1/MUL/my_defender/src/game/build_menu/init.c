/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init
*/

#include <stdlib.h>
#include "build_menu.h"
#include "core.h"
#include "cg.h"

void init_build_menu(t_list_t *list, b_menu_t *menu)
{
    menu->bomb = cg_load_sprite_form_file(NULL, &list->bomb);
    menu->fire = cg_load_sprite_form_file(NULL, &list->fire);
    menu->ice = cg_load_sprite_form_file(NULL, &list->ice);
    menu->thunder = cg_load_sprite_form_file(NULL, &list->thunder);
    menu->arrow = cg_load_sprite_form_file(NULL, &list->arrow);
    menu->sell = cg_load_sprite_form_file(NULL, &list->sell);
    menu->upgrade = cg_load_sprite_form_file(NULL, &list->upgrade);
    menu->status = false;
    menu->scale = (sfVector2f){0, 0};
}
