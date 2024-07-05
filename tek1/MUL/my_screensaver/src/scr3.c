/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** Third screensaver
*/

#include <time.h>
#include <stdlib.h>
#include "seal.h"

/*
** Random square placing
*/
framebuffer_t *scr3(framebuffer_t *buff)
{
    int x1 = rand() % 800;
    int y1 = rand() % 800;
    int x2 = rand() % 800;
    int y2 = rand() % 800;
    sfColor color;
    color.r = (sfUint8)(rand() % 255);
    color.g = (sfUint8)(rand() % 255);
    color.b = (sfUint8)(rand() % 255);
    color.a = (sfUint8)(rand() % 255);
    sl_put_rectangle(buff, x1, y1, x2, y2, color);
    return (buff);
}
