/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** disp_entry
*/

#include "my.h"
#include "ls.h"

void disp_entry(char const *str, args_t *args)
{
    if (args->paths_len > 1) {
        my_putstr(str);
        my_putstrln(":");
    }
}