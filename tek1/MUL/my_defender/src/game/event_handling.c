/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** event_handling
*/

#include "core.h"
#include "cg.h"
#include "functions.h"

void event_actor(core_t *core, sfRenderWindow *w, sfEvent evt)
{
    (void)core;
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(w);
}

void menu_event_handler(core_t *core, sfRenderWindow *w)
{
    tower_t *last_clicked = core->clicked;

    if (core->build_menu.status == OPENED)
        check_button_clicked(core, core->clicked, w);
    core->clicked = check_tower_click(core->towers,
        sfMouse_getPositionRenderWindow(w));
    if (core->clicked == last_clicked)
        core->clicked = NULL;
    if (core->clicked == NULL && core->build_menu.status != CLOSED)
        core->build_menu.status = CLOSING;
    else
        core->build_menu.status = CLOSED;
}

void event_handler(core_t *core, sfRenderWindow *w)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(w, &evt)) {
        event_actor(core, w, evt);
        if (evt.type == sfEvtMouseButtonPressed && evt.mouseButton.button
        == sfMouseLeft)
            menu_event_handler(core, w);
    }
}
