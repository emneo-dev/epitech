/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** check_button_clicked
*/

#include "core.h"
#include "cg.h"
#include "functions.h"

void check_more_button(core_t *core, tower_t *selected, sfRenderWindow *w)
{
    sfVector2i mouse_int = sfMouse_getPositionRenderWindow(w);
    sfVector2f mouse = {mouse_int.x, mouse_int.y};
    sfVector2f p = selected->position;

    if (cg_check_inbox(mouse, cg_vchange(p, -100, 0),
    cg_vchange(p, -50, 50)) && change_coin(&core->player, -125))
        set_tower_flame(core->t_list.tower_fire, selected);
    if (cg_check_inbox(mouse, cg_vchange(p, 0, 100),
    cg_vchange(p, 50, 150)) && change_coin(&core->player, -125))
        set_tower_frost(core->t_list.tower_ice, selected);
}

void check_tower_button(core_t *core, tower_t *selected, sfRenderWindow *w)
{
    sfVector2i mouse_int = sfMouse_getPositionRenderWindow(w);
    sfVector2f mouse = {mouse_int.x, mouse_int.y};
    sfVector2f p = selected->position;

    if (cg_check_inbox(mouse, cg_vchange(p, -100, 0),
    cg_vchange(p, -50, 50)))
        sell_tower(core->t_list.build_button, selected, &core->player);
}

void check_button_clicked(core_t *core, tower_t *selected, sfRenderWindow *w)
{
    sfVector2i mouse_int = sfMouse_getPositionRenderWindow(w);
    sfVector2f mouse = {mouse_int.x, mouse_int.y};
    sfVector2f p = selected->position;

    if (selected->type == NONE) {
        if (cg_check_inbox(mouse, cg_vchange(p, 100, 0),
        cg_vchange(p, 150, 50)) && change_coin(&core->player, -100))
            set_tower_electric(core->t_list.tower_elec, selected);
        if (cg_check_inbox(mouse, cg_vchange(p, 0, -150),
        cg_vchange(p, 50, -50)) && change_coin(&core->player, -125))
            set_tower_bomb(core->t_list.tower_bomb, selected);
        if (cg_check_inbox(mouse, cg_vchange(p, 75, 75),
        cg_vchange(p, 175, 175)) && change_coin(&core->player, -125))
            set_tower_arrow(core->t_list.tower_arrow, selected);
        check_more_button(core, selected, w);
    } else
        check_tower_button(core, selected, w);
}
