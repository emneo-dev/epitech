/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** Second screensaver
*/

#include <time.h>
#include <stdlib.h>
#include "seal.h"

/*
** Random pixel placing
*/
framebuffer_t *scr2(framebuffer_t *buff)
{
    int x = rand() % 800;
    int y = rand() % 800;
    sfColor color;
    color.r = (sfUint8)(rand() % 255);
    color.g = (sfUint8)(rand() % 255);
    color.b = (sfUint8)(rand() % 255);
    color.a = (sfUint8)(rand() % 255);
    sl_put_pixel(buff, x, y, color);
    return (buff);
}
