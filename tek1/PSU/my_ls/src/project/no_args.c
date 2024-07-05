/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** no_args
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"
#include "ls.h"

void no_print_args(DIR *current_dir, char const *str)
{
    struct dirent *file = NULL;

    if (!current_dir) {
        my_putstr("my_ls: cannot open directory '");
        my_putstr(str);
        my_putstr("': Permission denied\n");
        return;
    }
    while ((file = readdir(current_dir)) != NULL)
        if (file->d_name[0] != '.')
            my_putstrln(file->d_name);
}