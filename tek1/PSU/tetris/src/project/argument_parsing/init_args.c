/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_args
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

args_t *init_args(void)
{
    args_t *args = NULL;

    args = malloc(sizeof(args_t));
    if (!args)
        return (NULL);
    args->help = 0;
    args->level = 1;
    args->key_left = -1;
    args->key_right = -2;
    args->key_turn = -3;
    args->key_drop = -4;
    args->key_quit = 'q';
    args->key_pause = ' ';
    args->without_next = 0;
    args->debug = 0;
    args->map_size = malloc(sizeof(char) * 6);
    if (!args->map_size)
        return (NULL);
    my_strcpy(args->map_size, "20*10");
    return (args);
}