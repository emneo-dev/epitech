/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** draw_game
*/

#include "core.h"

void draw_towers(tower_t *list, sfRenderWindow *w)
{
    for (tower_t *last = list; last && last != NULL; last = last->next) {
        sfSprite_setTextureRect(last->sprite, last->rect);
        sfRenderWindow_drawSprite(w, last->sprite, NULL);
    }
}

void draw_enemy(enemy_t *list, sfRenderWindow *w)
{
    for (enemy_t *last = list; last != NULL; last = last->next) {
        sfSprite_setTextureRect(last->sprite, last->rect);
        sfRenderWindow_drawSprite(w, last->sprite, NULL);
    }
}

void draw_build_menu(core_t *core, tower_t *selected, sfRenderWindow *w)
{
    b_menu_t *menu = &core->build_menu;
    sfCircleShape *range = core->tow_range;
    float t_range = 0;

    if (selected == NULL)
        return;
    if (selected->type == NONE) {
        sfRenderWindow_drawSprite(w, menu->ice, NULL);
        sfRenderWindow_drawSprite(w, menu->fire, NULL);
        sfRenderWindow_drawSprite(w, menu->bomb, NULL);
        sfRenderWindow_drawSprite(w, menu->thunder, NULL);
        sfRenderWindow_drawSprite(w, menu->arrow, NULL);
    } else {
        t_range = selected->range;
        sfCircleShape_setRadius(range, selected->range);
        sfCircleShape_setPosition(range, (sfVector2f){selected->position.x -
        t_range + 25, selected->position.y - t_range + 25});
        sfRenderWindow_drawSprite(w, menu->upgrade, NULL);
        sfRenderWindow_drawSprite(w, menu->sell, NULL);
        sfRenderWindow_drawCircleShape(w, range, NULL);
    }
}

void draw_game(core_t *core, sfRenderWindow *w)
{
    sfRenderWindow_clear(w, sfBlack);
    sfRenderWindow_drawSprite(w, core->map, NULL);
    draw_towers(core->towers, w);
    if (core->build_menu.status != CLOSED)
        draw_build_menu(core, core->clicked, w);
    draw_enemy(core->enemy, w);
    if (core->data.status == INTERMISSION)
        sfRenderWindow_drawText(w, core->wave_text, NULL);
    sfRenderWindow_drawText(w, core->player.bal_text, NULL);
    sfRenderWindow_drawSprite(w, core->player.coin, NULL);
    sfRenderWindow_display(w);
}
