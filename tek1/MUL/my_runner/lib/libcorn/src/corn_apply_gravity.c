/*
** EPITECH PROJECT, 2019
** libcorn
** File description:
** corn_apply_gravity
*/

#include <SFML/Graphics.h>

void corn_apply_gravity(sfSprite *sprite, float g_force, float *speed)
{
    sfSprite_move(sprite, (sfVector2f){0, *speed});
    if (*speed < 0.f)
        *speed += g_force / 7;
    else
        *speed += g_force / 11;
}