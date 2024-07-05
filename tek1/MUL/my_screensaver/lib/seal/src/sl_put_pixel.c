/*
** EPITECH PROJECT, 2019
** seal
** File description:
** Put a pixel to the screen
*/

#include <seal.h>
#include <stdio.h>

void sl_put_pixel(framebuffer_t *buff, int x, int y, sfColor color)
{
    int pos = (x + y * buff->width) * 4;
    buff->pixels[pos] = color.r;
    buff->pixels[pos + 1] = color.g;
    buff->pixels[pos + 2] = color.b;
    buff->pixels[pos + 3] = color.a;
    return;
}
