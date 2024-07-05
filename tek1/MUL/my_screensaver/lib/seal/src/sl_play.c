/*
** EPITECH PROJECT, 2019
** seal
** File description:
** Main file to run the program
*/

#include <seal.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>

static void is_close(window_info_t *info)
{
    while (sfRenderWindow_pollEvent(info->window, info->event))
        if (info->event->type == sfEvtClosed)
            sfRenderWindow_close(info->window);
    return;
}

int sl_play(void *uinfo)
{
    window_info_t *info = sl_init("my_screensaver");
    info->to_pass = uinfo;
    sfRenderWindow_setFramerateLimit(info->window, 60);
    info->buff = init(info->buff, info->to_pass);
    while (sfRenderWindow_isOpen(info->window)) {
        is_close(info);
        info->buff = loop(info->buff, info->to_pass);
        sfRenderWindow_clear(info->window, sfBlack);
        sfTexture_updateFromPixels(info->texture, info->buff->pixels, 800, 800,
            0, 0);
        sfSprite_setTexture(info->sprite, info->texture, sfFalse);
        sfRenderWindow_drawSprite(info->window, info->sprite, NULL);
        sfRenderWindow_display(info->window);
    }
    sfRenderWindow_destroy(info->window);
    return (0);
}
