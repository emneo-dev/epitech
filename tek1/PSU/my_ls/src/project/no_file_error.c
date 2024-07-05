/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** no_file_error
*/

#include "my.h"

void no_file(char const *str)
{
    my_putstr("my_ls: cannot access '");
    my_putstr(str);
    my_putstr("': No such file or directory\n");
}