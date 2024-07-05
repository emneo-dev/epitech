/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
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