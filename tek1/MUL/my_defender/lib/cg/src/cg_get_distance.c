/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** cg_get_distance
*/

#include <SFML/Graphics/Vertex.h>

float cg_get_distance(sfVector2f v1, sfVector2f v2)
{
    float dist_x = 0;
    float dist_y = 0;

    dist_x = v1.x - v2.x;
    dist_y = v1.y - v2.y;
    dist_x *= (dist_x < 0) ? -1 : 1;
    dist_y *= (dist_y < 0) ? -1 : 1;
    return (dist_x + dist_y);
}