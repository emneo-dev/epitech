/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** drawing
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size,
    uint32_t color)
{
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            img[y + origin->y][x + origin->x] = color;
}