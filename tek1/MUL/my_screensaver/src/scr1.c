/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** First screensaver
*/

#include <time.h>
#include <stdlib.h>
#include "seal.h"

/*
** Random pixel placing
*/
framebuffer_t *scr1(framebuffer_t *buff)
{
    int x = rand() % 800;
    int y = rand() % 800;
    sl_put_pixel(buff, x, y, sfWhite);
    return (buff);
}
