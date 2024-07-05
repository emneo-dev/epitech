/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_talk_text
*/

#include "utility.h"
#include "talk/structs.h"

static int fill_talk_box(sfRenderWindow *window)
{
    sfRectangleShape *box = NULL;

    sfRenderWindow_clear(window, sfWhite);
    box = sfRectangleShape_create();
    if (!box) {
        my_puterr("Could not create text box!");
        return (1);
    }
    sfRectangleShape_setPosition(box, (sfVector2f) {0, 500});
    sfRectangleShape_setSize(box, (sfVector2f) {1000, 500});
    sfRectangleShape_setFillColor(box, sfGreen);
    sfRenderWindow_drawRectangleShape(window, box, NULL);
    sfRectangleShape_destroy(box);
    return (0);
}

int display_talk_text(sfText *text, sfRenderWindow *window)
{
    if (fill_talk_box(window))
        return (1);
    sfRenderWindow_drawText(window, text, NULL);
    return (0);
}