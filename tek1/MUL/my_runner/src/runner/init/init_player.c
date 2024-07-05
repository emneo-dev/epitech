/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** init_player
*/

#include <stdlib.h>
#include "corn.h"
#include "my_runner.h"

static sfIntRect init_player_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 432;
    rect.height = 302;
    return (rect);
}

player_t *init_player(void)
{
    player_t *player = NULL;
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    player = malloc(sizeof(player_t));
    if (!player)
        return (NULL);
    sprite = corn_load_sprite_from_file(PLAYER_FILE, &texture);
    if (!sprite)
        return (NULL);
    player->speed = -10;
    player->rect = init_player_rect();
    player->clock = sfClock_create();
    if (!player->clock)
        return (NULL);
    player->sprite = sprite;
    player->texture = texture;
    sfSprite_setPosition(player->sprite, (sfVector2f) {200, 200});
    return (player);
}