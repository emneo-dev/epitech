/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** destroy_parralax
*/

#include <stdlib.h>
#include "my_runner.h"

void destroy_parralax(parralax_t *parralax)
{
    parralax_t *next = NULL;

    while (parralax) {
        sfSprite_destroy(parralax->sprite);
        sfTexture_destroy(parralax->texture);
        sfSprite_destroy(parralax->sprite_2);
        sfTexture_destroy(parralax->texture_2);
        next = parralax->next;
        free(parralax);
        parralax = next;
    }
}