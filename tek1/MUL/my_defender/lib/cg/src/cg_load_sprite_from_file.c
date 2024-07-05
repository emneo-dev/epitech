/*
** EPITECH PROJECT, 2019
** cg
** File description:
** cg_load_sprite
*/

#include <SFML/Graphics.h>

sfSprite *cg_load_sprite_form_file(char *filepath, sfTexture **texture)
{
    sfSprite *new = NULL;

    if (*texture == NULL && filepath != NULL)
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