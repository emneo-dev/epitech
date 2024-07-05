/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_putstrln
*/

#include <unistd.h>
#include "my.h"

int my_putstrln(char const *str)
{
    my_putstr(str);
    write(1, "\n", 1);
    return (my_strlen(str) + 1);
}