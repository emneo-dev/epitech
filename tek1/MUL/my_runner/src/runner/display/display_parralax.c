/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** display_parralax
*/

#include "my_runner.h"
#include "corn.h"

static int is_out_of_band(sfSprite *sprite)
{
    sfVector2f position = sfSprite_getPosition(sprite);
    return ((position.x <= -1152) ? 1 : 0);
}

void display_parralax(game_object_t *objects, long double speed)
{
    parralax_t *current = objects->parralax;

    for (int i = 0; current; current = current->next, i++) {
        sfRenderWindow_drawSprite(objects->window, current->sprite, NULL);
        sfSprite_move(current->sprite, (sfVector2f) {-1 * i * speed, 0});
        sfRenderWindow_drawSprite(objects->window, current->sprite_2, NULL);
        sfSprite_move(current->sprite_2, (sfVector2f) {-1 * i * speed, 0});
        if (is_out_of_band(current->sprite)) {
            sfSprite_setPosition(current->sprite, (sfVector2f) {0, 0});
            sfSprite_setPosition(current->sprite_2, (sfVector2f) {1152, 0});
        }
    }
}