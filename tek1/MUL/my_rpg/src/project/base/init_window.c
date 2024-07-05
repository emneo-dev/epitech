/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** window_init
*/

#include <SFML/Graphics.h>

sfRenderWindow *init_window(char const *name, sfVector2u size)
{
    sfVideoMode vm = {size.x, size.y, 32};
    sfRenderWindow *window = sfRenderWindow_create(vm,
                                                    name,
                                                    sfClose,
                                                    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}