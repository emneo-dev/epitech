/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Returns whether or not an enemy is in range of a tower
*/

#include <math.h>
#include <tower.h>
#include <SFML/Graphics.h>

// Returns the middle of an sfFloatRect
static sfVector2f get_rect_middle(sfFloatRect const a)
{
    sfVector2f middle;

    middle.x = a.left + a.width / 2;
    middle.y = a.top + a.height / 2;
    return (middle);
}

// Just some pythagorean thingy to get the distance between two points
// in a 2D environment
static float get_distance(sfVector2f const a, sfVector2f const b)
{
    return (sqrt(pow((a.x + b.x) / 2, 2) * pow((a.y + b.y) / 2, 2)));
}

// Returns whether or not an enemy is in range of a tower
int is_in_range(sfFloatRect const enemy, tower_t const *tower)
{
    sfVector2f middle_enemy;

    middle_enemy = get_rect_middle(enemy);
    return (get_distance(middle_enemy, tower->position) <= tower->range);
}