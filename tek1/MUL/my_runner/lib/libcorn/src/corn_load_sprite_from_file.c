/*
** EPITECH PROJECT, 2019
** libcorn
** File description:
** corn_load_sprite_from_file
*/

#include <SFML/Graphics.h>

/**
* \file corn_load_sprite_from_file.c
* \author Alexandre Descoins
* \version 1
*/
sfSprite *corn_load_sprite_from_file(char const *filepath, sfTexture **texture)
{
    sfSprite *new = NULL;

    *texture = sfTexture_createFromFile(filepath, NULL);
    if (*texture == NULL)
        return (NULL);
    new = sfSprite_create();
    if (new == NULL) {
        sfTexture_destroy(*texture);
        return (NULL);
    }
    sfSprite_setTexture(new, *texture, sfFalse);
    return (new);
}