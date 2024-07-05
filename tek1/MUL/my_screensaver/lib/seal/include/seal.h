/*
** EPITECH PROJECT, 2019
** seal
** File description:
** Header file for the seal library
*/

#ifndef SEAL_H
#define SEAL_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>

typedef struct framebuffer {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

typedef struct window_info {
    sfRenderWindow *window;
    sfVideoMode vm;
    sfTexture *texture;
    sfSprite *sprite;
    framebuffer_t *buff;
    sfEvent *event;
    void *to_pass;
    sfTime framerate;
} window_info_t;

window_info_t *sl_init(char *name);
int sl_play(void *uinfo);
framebuffer_t *loop(framebuffer_t *buff, void *to_pass);
framebuffer_t *init(framebuffer_t *buff, void *to_pass);
framebuffer_t *sl_framebuffer_create(unsigned int width, unsigned int height);
void sl_put_pixel(framebuffer_t *buff, int x, int y, sfColor color);
void sl_put_rectangle(framebuffer_t *buff, int x1, int y1, int x2, int y2,
    sfColor color);

#endif /* SEAL_H */
