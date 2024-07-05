/*
** EPITECH PROJECT, 2019
** cg_check_clock.c
** File description:
** cg_move_rect
*/

#include <SFML/Graphics.h>

void cg_move_rect(sfIntRect *rect, int move, int maximum)
{
    rect->left += move;
    if (rect->left > maximum)
        rect->left = 0;
}