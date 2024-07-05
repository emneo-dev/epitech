/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_font
*/

#include "talk/structs.h"
#include "utility.h"

int init_font(talk_t *talk, char *font_path)
{
    if (!font_path) {
        my_puterr("Could not create font!\n");
        return (1);
    }
    talk->font = sfFont_createFromFile(font_path);
    if (!talk->font) {
        my_puterr("Could not create font!\n");
        return (1);
    }
    return (0);
}