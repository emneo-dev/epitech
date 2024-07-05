/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** menu
*/

#include "rpg.h"

int init_texture_menu(m_menu *menu)
{
    menu->coin = create_object("./res/img/coin.png", 1180, 120);
    menu->background = create_object("./res/img/wallpaper.jpg"
        , 0, 0);
    menu->background2 = create_object("./res/img/wallpaper2.jpg"
        , 1280, 0);
    menu->button_play = create_object("./res/img/button_play.png",
        250, 75);
    menu->button_quit = create_object("./res/img/button_quit.png",
        250, 650);
    init_hitbox(menu->button_play);
    init_hitbox(menu->button_quit);
    return (0);
}

void display_menu(sfRenderWindow *window, m_menu *menu)
{
    sfIntRect rect;
    rect.top = 0;
	rect.left = 0;
    rect.width = 100;
	rect.height = 100;
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->button_play->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->background2->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->button_quit->sprite, NULL);
    sfSprite_setTextureRect(menu->coin->sprite, rect);
    move_coin(menu);
    sfRenderWindow_drawSprite(window, menu->coin->sprite, NULL);
    sfRenderWindow_display(window);
}

void destroy_menu(m_menu *menu)
{
    destroy_object(menu->background);
    destroy_object(menu->button_play);
    destroy_object(menu->button_quit);
}

void move_coin(m_menu *menu)
{
    sfTime time;
    float seconds;
    sfIntRect rect;
    sfClock *clock;

    clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100.0;
	if (seconds > 0 && seconds < 3) {
        rect.top = 322;
	    rect.left = 51;
	    rect.width = 6;
	    rect.height = 81;
        sfSprite_setTextureRect(menu->coin->sprite, rect);
    }
    if (seconds > 3)
        sfClock_restart(clock);

}