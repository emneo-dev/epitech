/*
** EPITECH PROJECT, 2019
** seal
** File description:
** Creates a framebuffer ready to use
*/

#include <seal.h>
#include <stdlib.h>

framebuffer_t *sl_framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buff = malloc(sizeof(framebuffer_t));
    buff->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    buff->width = width;
    buff->height = height;
    return (buff);
}
