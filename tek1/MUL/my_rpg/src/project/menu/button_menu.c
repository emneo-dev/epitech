/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** manage_menu
*/

#include "rpg.h"

int button_quit(m_menu *menu, sfRenderWindow *window)
{
    sfBool click = button_pressed(menu->button_quit, window);
    sfBool passe = is_mouse_on_object(menu->button_quit, window);

    if (click == sfTrue)
       return (1);
    if (passe == sfTrue)
        sfSprite_setScale(menu->button_quit->sprite, (sfVector2f) {1.25, 1.25});
    if (passe == sfFalse)
        sfSprite_setScale(menu->button_quit->sprite, (sfVector2f) {1, 1});
    return (0);
}

int button_play(m_menu *menu, sfRenderWindow *window)
{
    sfBool click = button_pressed(menu->button_play, window);
    sfBool passe = is_mouse_on_object(menu->button_play, window);

    if (click == sfTrue)
        return (1);
    if (passe == sfTrue)
        sfSprite_setScale(menu->button_play->sprite, (sfVector2f) {1.25, 1.25});
    if (passe == sfFalse)
        sfSprite_setScale(menu->button_play->sprite, (sfVector2f) {1, 1});
    return (0);
}

int m_button_menu(m_menu *menu, sfRenderWindow *window)
{
    if (button_quit(menu, window))
        return (2);
    else if (button_play(menu, window))
        return (1);
    return (0);
}
