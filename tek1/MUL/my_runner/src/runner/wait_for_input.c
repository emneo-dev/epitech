/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** wait_for_input
*/

#include "corn.h"
#include "my_runner.h"

static void destroy_menu(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

static void display_menu(game_object_t *objects, sfSprite *sprite)
{
    sfRenderWindow_clear(objects->window, sfWhite);
    sfRenderWindow_drawSprite(objects->window, sprite, NULL);
    sfRenderWindow_display(objects->window);
}

void wait_for_input(game_object_t *objects)
{
    sfEvent event;
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    sprite = corn_load_sprite_from_file(SPACE, &texture);
    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setPosition(sprite, (sfVector2f) {106, 321});
    display_menu(objects, sprite);
    while (sfRenderWindow_pollEvent(objects->window, &event) ||
            sfRenderWindow_isOpen(objects->window)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(objects->window);
        else if (event.type == sfEvtKeyPressed &&
                sfKeyboard_isKeyPressed(sfKeySpace)) {
            sfClock_restart(objects->g_clock);
            destroy_menu(sprite, texture);
            return;
        }
        display_menu(objects, sprite);
    }
}