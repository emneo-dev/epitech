/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** final_screen
*/

#include "corn.h"
#include "my_runner.h"

static void destroy_menu(sfText *text)
{
    sfText_destroy(text);
}

static void display_menu(game_object_t *objects, sfText *text, sfText *score)
{
    sfRenderWindow_clear(objects->window, sfWhite);
    sfRenderWindow_drawText(objects->window, text, NULL);
    sfRenderWindow_drawText(objects->window, score, NULL);
    sfRenderWindow_display(objects->window);
}

void final_screen(game_object_t *objects)
{
    sfEvent event;
    sfText *text = NULL;
    sfTime time = sfClock_getElapsedTime(objects->g_clock);
    sfText *score = corn_create_text("0", 100, objects->my_font, sfRed);

    sfText_setString(score,
        int_to_string((long long int) sfTime_asMicroseconds(time)));
    if (objects->is_won)
        text = corn_create_text("You won!", 100, objects->my_font, sfBlack);
    else
        text = corn_create_text("You lost", 100, objects->my_font, sfBlack);
    sfText_setPosition(score, (sfVector2f) {400, 400});
    sfText_setPosition(text, (sfVector2f) {106, 321});
    while (!sfRenderWindow_pollEvent(objects->window, &event))
        display_menu(objects, text, score);
    destroy_menu(text);
}