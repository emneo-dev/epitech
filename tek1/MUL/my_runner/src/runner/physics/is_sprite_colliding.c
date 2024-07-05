/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** is_sprite_colliding
*/

#include <SFML/Graphics.h>

int is_sprite_colliding(sfSprite *a, sfSprite *b)
{
    sfFloatRect a_rect = sfSprite_getGlobalBounds(a);
    sfFloatRect b_rect = sfSprite_getGlobalBounds(b);
    return (sfFloatRect_intersects(&a_rect, &b_rect, NULL));
}