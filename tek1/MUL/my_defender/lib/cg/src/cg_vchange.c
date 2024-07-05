/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** cg_vchange
*/

#include <SFML/Graphics/Vertex.h>

sfVector2f cg_vchange(sfVector2f v, float x, float y)
{
    v.x += x;
    v.y += y;
    return (v);
}