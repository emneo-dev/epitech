/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_two_options
*/

#include "talk/internal.h"

static int handle_talk_events_mouse(talk_t *talk, cb_talk_node_t *cb,
                                    sfRenderWindow *window)
{
    if (sfMouse_getPositionRenderWindow(window).y >= 800 &&
        sfMouse_getPositionRenderWindow(window).x <= 300) {
        cb->is_end = talk->node[cb->index]->is_end;
        cb->index = talk->node[cb->index]->first_option_index;
        return (0);
    }
    else if (sfMouse_getPositionRenderWindow(window).y >= 800 &&
        sfMouse_getPositionRenderWindow(window).x >= 700) {
        cb->is_end = talk->node[cb->index]->is_end;
        cb->index = talk->node[cb->index]->second_option_index;
        return (0);
    }
    return (1);
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

void display_two_options(talk_t *talk, cb_talk_node_t *cb,
                         sfRenderWindow *window)
{
    if (display_talk_text(talk->node[cb->index]->text, window)) {
        cb->is_end = 1;
        return;
    }
    display_left_option(talk->node[cb->index]->first_option, window);
    display_right_option(talk->node[cb->index]->second_option, window);
    sfRenderWindow_display(window);
    while (handle_talk_events(talk, cb, window));
}