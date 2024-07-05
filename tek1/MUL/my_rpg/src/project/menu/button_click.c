/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** bottom is clicked
*/

#include <stdlib.h>
#include "rpg.h"
#include <stdio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>


sfBool is_mouse_on_object(game_object_t *object, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfBool condition = sfFalse;

    condition = sfIntRect_contains(object->hitbox, mouse.x, mouse.y);
    return (condition);
}

sfBool mouse_button_pressed(void)
{
    sfMouseButton mouse = sfMouseLeft;
    sfBool condition = sfMouse_isButtonPressed(mouse);

    return(condition);
}

sfBool button_pressed(game_object_t *object, sfRenderWindow *window)
{
    sfBool pos = sfFalse;
    sfBool pressed = sfFalse;
    sfBool condition = sfFalse;

    pos = is_mouse_on_object(object, window);
    pressed = mouse_button_pressed();
    if (pos == sfTrue && pressed == sfTrue)
        condition = sfTrue;
    return (condition);
}