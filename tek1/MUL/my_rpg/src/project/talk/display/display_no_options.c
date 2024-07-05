/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_no_options
*/

#include "talk/internal.h"

static int handle_talk_events_mouse(talk_t *talk, cb_talk_node_t *cb,
                                    sfRenderWindow *window)
{
    if (sfMouse_getPositionRenderWindow(window).y < 500)
        return (1);
    cb->is_end = talk->node[cb->index]->is_end;
    cb->index = talk->node[cb->index]->first_option_index;
    return (0);
}

static int handle_talk_events(talk_t *talk, cb_talk_node_t *cb,
                              sfRenderWindow *window)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            cb->is_end = 1;
            return (0);
        }
        else if (event.type == sfEvtMouseButtonPressed)
            return (handle_talk_events_mouse(talk, cb, window));
    }
    return (1);
}

void display_no_options(talk_t *talk, cb_talk_node_t *cb,
                        sfRenderWindow *window)
{
    if (display_talk_text(talk->node[cb->index]->text, window)) {
        cb->is_end = 1;
        return;
    }
    sfRenderWindow_display(window);
    while (handle_talk_events(talk, cb, window));
}