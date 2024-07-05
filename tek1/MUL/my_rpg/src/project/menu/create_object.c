/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** create_object
*/

#include <stdlib.h>
#include "rpg.h"

void init_hitbox(game_object_t *object)
{
    sfVector2u size_texture = sfTexture_getSize (object->texture);

    object->hitbox->top = object->pos.y;
    object->hitbox->left = object->pos.x;
    object->hitbox->width = size_texture.x;
    object->hitbox->height = size_texture.y;
}

game_object_t *create_object (char *path, int x, int y)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    object->texture = malloc(sizeof(sfTexture *));
    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->pos.x = x;
    object->pos.y = y;
    object->move.x = 1;
    object->move.y = 1;
    sfSprite_setPosition(object->sprite, object->pos);
    object->hitbox = malloc(sizeof(sfIntRect));
    init_hitbox(object);
    return (object);
}

void move_object(game_object_t *object)
{
    object->pos.x += object->move.x;
    object->pos.y += object->move.y;
    sfSprite_setPosition(object->sprite, object->pos);
}

void destroy_object(game_object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
}
