/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** initialize_inventory
*/

#include <stdlib.h>
#include "utility.h"
#include "rpg.h"

int initialize_inventory(inventory_t *inventory, char *path)
{
    inventory->texture = sfTexture_createFromFile(path, NULL);
    if (!inventory->texture)
        return (my_puterr("Could not init inventory texture!\n") - 1);
    inventory->nb_of_slot = 5;
    return (0);
}
