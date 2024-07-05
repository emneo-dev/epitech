/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** destroy_menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu_struct.h"

static void destroy_buttons(button_t *button)
{
    button_t *next = NULL;

    while (button) {
        next = button->next;
        sfText_destroy(button->text);
        free(button);
        button = next;
    }
}

void destroy_menu(menu_t *menu)
{
    sfTexture_destroy(menu->bg_texture);
    sfSprite_destroy(menu->background);
    destroy_buttons(menu->b_list);
    sfMusic_destroy(menu->ambient);
    sfFont_destroy(menu->font);
}
