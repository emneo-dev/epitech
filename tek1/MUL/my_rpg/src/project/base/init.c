/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init
*/

#include <stdlib.h>
#include "utility.h"
#include "rpg.h"

int base_init(core_t *core)
{
    core->window = init_window("my_rpg", (sfVector2u) {1000, 1000});
    if (!core->window)
        return ((int) my_puterr("Could not initialize window!\n") - 1);
    return (0);
}