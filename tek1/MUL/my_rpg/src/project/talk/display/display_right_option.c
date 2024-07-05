/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_options
*/

#include "utility.h"
#include "talk/structs.h"

static int fill_talk_box(sfRenderWindow *window)
{
    sfRectangleShape *box = NULL;

    box = sfRectangleShape_create();
    if (!box) {
        my_puterr("Could not create text box!");
        return (1);
    }
    sfRectangleShape_setPosition(box, (sfVector2f) {0, 800});
    sfRectangleShape_setSize(box, (sfVector2f) {300, 200});
    sfRectangleShape_setFillColor(box, sfYellow);
    sfRenderWindow_drawRectangleShape(window, box, NULL);
    sfRectangleShape_destroy(box);
    return (0);
}

int display_left_option(sfText *text, sfRenderWindow *window)
{
    if (fill_talk_box(window))
        return (1);
    sfRenderWindow_drawText(window, text, NULL);
    return (0);
}