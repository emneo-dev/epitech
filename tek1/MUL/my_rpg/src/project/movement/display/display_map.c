/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_map
*/

#include <stdio.h>
#include "utility.h"
#include "movement/internal.h"
#include "movement/structs.h"

static int handle_events(map_t *map, sfRenderWindow *window, sfClock *clock)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed)
            return (event_handler(window, map, clock));
    }
    return (0);
}

static void player_display(sfRenderWindow *window, player_t *player,
                           sfSprite *sprite)
{
    sfSprite_setTexture(sprite, player->texture, sfTrue);
    sfSprite_setPosition(sprite, player->pos);
    sfSprite_setScale(sprite, (sfVector2f) {1, 1});
    if (cg_check_clock(player->clock, 0.20f, sfTrue))
        cg_move_rect(&player->rect, 40, 199);
    sfSprite_setTextureRect(sprite, player->rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

static void base_map_display(map_t *map, sfRenderWindow *window,
                             sfSprite *sprite)
{
    sfVector2u size = sfTexture_getSize(map->texture);

    sfRenderWindow_clear(window, sfWhite);
    sfSprite_setTexture(sprite, map->texture, sfTrue);
    sfSprite_setPosition(sprite, map->pos);
    sfSprite_setScale(sprite, (sfVector2f) {size.x / map->size.x,
                                            size.y / map->size.y});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    player_display(window, map->player, sprite);
    sfRenderWindow_display(window);
}

// Returns 0 when wants to close the game
// else returns the number of the next map
int display_map(map_t *map, sfRenderWindow *window)
{
    sfSprite *sprite = NULL;
    int tmp = 0;
    sfClock *clock = sfClock_create();

    sprite = sfSprite_create();
    if (!sprite) {
        my_puterr("Could not display map! (sprite creation failed)");
        return (0);
    }
    map->player->pos = map->start_pos;
    sfClock_restart(map->player->clock);
    while (sfRenderWindow_isOpen(window)) {
        base_map_display(map, window, sprite);
        if ((tmp = handle_events(map, window, clock)))
            return (tmp);
        sfClock_restart(clock);
    }
    return (0);
}