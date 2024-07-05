/*
** EPITECH PROJECT, 2020
** auto_menu
** File description:
** draw_menu
*/

#include "menu_struct.h"

void draw_menu(menu_t *menu)
{
    sfRenderWindow_clear(menu->w, sfBlack);
    sfRenderWindow_drawSprite(menu->w, menu->background, NULL);
    for (button_t *but = menu->b_list; but; but = but->next)
        sfRenderWindow_drawText(menu->w, but->text, NULL);
    sfRenderWindow_display(menu->w);
}
