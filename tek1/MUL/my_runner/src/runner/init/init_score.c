/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** init_score
*/

#include "corn.h"
#include "my_runner.h"

void init_score(game_object_t *objects)
{
    objects->g_clock = sfClock_create();
    objects->my_font = sfFont_createFromFile(TYP);
    objects->score = corn_create_text("0", 50, objects->my_font, sfYellow);
}