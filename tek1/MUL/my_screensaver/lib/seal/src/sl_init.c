/*
** EPITECH PROJECT, 2019
** seal
** File description:
** Initialise a basic window and a frame buffer
*/

#include <seal.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

window_info_t *sl_init(char *name)
{
    window_info_t *ret = malloc(sizeof(window_info_t));
    sfVideoMode vm = {800, 800, 32};
    ret->vm = vm;
    ret->texture = sfTexture_create(800, 800);
    ret->sprite = sfSprite_create();
    ret->window = sfRenderWindow_create(ret->vm, name, sfClose, 0);
    ret->buff = sl_framebuffer_create(800, 800);
    ret->event = malloc(sizeof(sfEvent));
    ret->framerate.microseconds = 16667;
    return (ret);
}
