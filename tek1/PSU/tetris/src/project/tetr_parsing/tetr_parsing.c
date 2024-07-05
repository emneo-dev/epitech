/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetr_parsing
*/

#include <dirent.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"
#include "prototype.h"

tetr_t *tetr_parsing(void)
{
    DIR *current_dir = NULL;
    FILE *ofile = NULL;
    int i = 0;

    current_dir = opendir("./tetriminos/");
    return (setup_while(i, current_dir, ofile));
}