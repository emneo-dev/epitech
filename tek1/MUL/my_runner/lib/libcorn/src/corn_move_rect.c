/*
** EPITECH PROJECT, 2019
** libcorn
** File description:
** corn_move_rect
*/

#include <SFML/Graphics.h>

/**
* \file corn_move_rect.c
* \author Alexandre Descoins
* \version 1
*/
void corn_move_rect(sfIntRect *rect, int move, int maximum)
{
    rect->left += move;
    if (rect->left > maximum)
        rect->left = 0;
}