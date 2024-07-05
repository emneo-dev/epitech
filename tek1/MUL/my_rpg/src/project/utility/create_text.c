/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** create_text
*/

#include <SFML/Graphics.h>
#include "utility.h"

sfText *create_text(const char *str, int size, sfFont *font, sfColor color)
{
    sfText *text = sfText_create();

    if (!text) {
        my_putwarn("Could not create text!\n");
        return (NULL);
    }
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    sfText_setOutlineThickness(text, 2);
    sfText_setStyle(text, sfTextBold);
    return (text);
}