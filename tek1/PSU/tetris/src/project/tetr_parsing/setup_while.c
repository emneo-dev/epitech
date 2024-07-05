/*
** EPITECH PROJECT, 2020
** PSU_tetris
** File description:
** setup_while
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "prototype.h"
#include "my.h"

static int setup_name(tetr_t *new, struct dirent *file)
{
    new->name = malloc(sizeof(char) * (my_strlen(file->d_name) + 1));
    if (!new->name)
        return (EXIT_FAILURE);
    my_strcpy(new->name, file->d_name);
    return (EXIT_SUCCESS);
}

static int setup_int(tetr_t *new, char *tmp, int i)
{
    new->width = my_getnbr(tmp);
    for (i = 0; tmp[i] != ' '; i++);
    i++;
    new->height = my_getnbr(tmp + i);
    i++;
    for (; tmp[i] != ' '; i++);
    i++;
    new->color = my_getnbr(tmp + i);
    return (i);
}

static int setup_normal(tetr_t *new, char *tmp, FILE *ofile, int i)
{
    size_t nb_read = 0;

    new->normal = malloc(sizeof(char *) * new->height);
    if (!new->normal)
        return (EXIT_FAILURE);
    for (i = 0; i < new->height; i++) {
        new->normal[i] = malloc(sizeof(char) * (new->width + 1));
        if (!new->normal[i])
            return (EXIT_FAILURE);
        getline(&tmp, &nb_read, ofile);
        change_carriage(tmp);
        my_strcpy(new->normal[i], tmp);
    }
    return (EXIT_SUCCESS);
}

static int setup_ofile(tetr_t *new, FILE *ofile, char *tmp, int i)
{
    size_t nb_read = 0;

    ofile = fopen(append("./tetriminos/", new->name), "r");
    if (!ofile)
        return (EXIT_FAILURE);
    getline(&tmp, &nb_read, ofile);
    setup_int(new, tmp, i);
    if (setup_normal(new, tmp, ofile, i))
        return (EXIT_FAILURE);
    fclose(ofile);
    return (EXIT_SUCCESS);
}

tetr_t *setup_while(int i, DIR *current_dir, FILE *ofile)
{
    char *tmp = NULL;
    struct dirent *file = NULL;
    tetr_t *current = NULL;
    tetr_t *new = NULL;

    while ((file = readdir(current_dir)) != NULL) {
        if (file->d_name[0] != '.') {
            new = malloc(sizeof(tetr_t));
            if (!new)
                return (NULL);
            if (setup_name(new, file))
                return (NULL);
            if (setup_ofile(new, ofile, tmp, i))
                return (NULL);
            new->next = current;
            current = new;
        }
    }
    return (current);
}