/*
** EPITECH PROJECT, 2019
** seal
** File description:
** Put a rectangle to the screen
*/

#include <seal.h>

void sl_put_rectangle(framebuffer_t *buff, int x1, int y1, int x2, int y2,
    sfColor color)
{
    for (int x = x1; x < x2; x++)
        for (int y = y1; y < y2; y++)
            sl_put_pixel(buff, x, y, color);
    return;
}