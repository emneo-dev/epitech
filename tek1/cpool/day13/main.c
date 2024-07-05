/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** Main file for the CSFML discovery
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

struct framebuffer_t *framebuffer_create(unsigned int width,
    unsigned int height);

void draw_square(struct framebuffer_t *framebuffer, sfVector2u position,
    unsigned int size, sfColor color);

struct framebuffer_t
{
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
};

int main(int argc, char const *argv[])
{
    sfRenderWindow *window;
    sfVideoMode vm = {800, 800, 32};
    sfTexture *texture = sfTexture_create(800, 800);
    sfSprite *sprite = sfSprite_create();
    sfVector2u positionlol = {100, 100};

    struct framebuffer_t *buffer = framebuffer_create(800, 800);
    window = sfRenderWindow_create(vm, "My Window", sfResize | sfClose, 0);
    put_all_pixels(buffer);
    draw_square(buffer, positionlol, 10, sfBlue);
    sfTexture_updateFromPixels(texture, buffer->pixels, 800, 800, 0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, 0);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}

struct framebuffer_t *framebuffer_create(unsigned int width,
    unsigned int height)
{
    struct framebuffer_t *buffer = malloc(sizeof(struct framebuffer_t));
    buffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    buffer->width = width;
    buffer->height = height;
    return (buffer);
}

void put_pixel(struct framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color)
{
    int index = (framebuffer->width * y + x) * 4;
    framebuffer->pixels[index] = color.r;
    framebuffer->pixels[index + 1] = color.g;
    framebuffer->pixels[index + 2] = color.b;
    framebuffer->pixels[index + 3] = color.a;
}

void put_all_pixels(struct framebuffer_t *buffer)
{
    put_pixel(buffer, 10, 10, sfRed);
    put_pixel(buffer, 100, 100, sfRed);
    put_pixel(buffer, 250, 400, sfRed);
}

void draw_square(struct framebuffer_t *framebuffer, sfVector2u position,
    unsigned int size, sfColor color)
{
    for (int i = position.x; i <= position.x + size; i++)
        for (int z = position.y; z <= position.y + size; z++) {
            put_pixel(framebuffer, i + position.x, z + position.y, color);
        }
}