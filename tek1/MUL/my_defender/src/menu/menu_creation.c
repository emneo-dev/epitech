/*
** EPITECH PROJECT, 2020
** auto_menu
** File description:
** menu_creation
*/

#include <SFML/Graphics.h>
#include "menu_struct.h"
#include <stdlib.h>
#include <string.h>
#include "cg.h"
#include "my.h"

static void set_text_props(sfText *text, fast_button_t info, sfVector2f pos)
{
    sfText_setString(text, info.name);
    sfText_setCharacterSize(text, info.size);
    sfText_setFont(text, info.font);
    sfText_setOutlineThickness(text, info.thickness);
    sfText_setColor(text, info.color);
    sfText_setPosition(text, pos);
}

void create_clickable_text(menu_t *menu, fast_button_t info, sfVector2f pos)
{
    button_t *last = menu->b_list;
    button_t *new = malloc(sizeof(struct button));
    sfText *text = sfText_create();

    set_text_props(text, info, pos);
    new->value = info.value;
    new->text = text;
    new->size = info.size;
    new->nb_char = my_strlen(info.name);
    new->next = last;
    menu->b_list = new;
}

int load_menu(sfRenderWindow *window, menu_t *menu)
{
    menu->status = 0;
    menu->font = sfFont_createFromFile("res/font/menu.ttf");
    menu->b_list = NULL;
    menu->w = window;
    menu->b_list = NULL;
    create_clickable_text(menu, (fast_button_t)
    {"Castle Guard", 0, 120, menu->font, sfBlack, 0}, (sfVector2f){320, 80});
    create_clickable_text(menu, (fast_button_t)
    {"Jouer", 1, 65, menu->font, sfYellow, 0}, (sfVector2f){590, 300});
    create_clickable_text(menu, (fast_button_t)
    {"Quitter", -1, 65, menu->font, sfYellow, 0}, (sfVector2f){575, 480});
    menu->bg_texture = NULL;
    menu->background = cg_load_sprite_form_file("res/sprites/menu.png",
    &menu->bg_texture);
    menu->ambient = sfMusic_createFromFile("res/audio/menu.ogg");
    sfMusic_setLoop(menu->ambient, sfTrue);
    return (0);
}
