/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** display_inventory
*/

#include "utility.h"
#include "rpg.h"

static int evt_inv(void)
{
    return (!sfKeyboard_isKeyPressed(sfKeyEscape));
}

int display_inventory(inventory_t *inventory, sfRenderWindow *window)
{
    sfSprite *sprite = NULL;

    sprite = sfSprite_create();
    if (!sprite)
        return (my_puterr("Could not create inventory sprite!\n") - 1);
    sfSprite_setTexture(sprite, inventory->texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    sfSprite_destroy(sprite);
    while (evt_inv());
    return (0);
}
