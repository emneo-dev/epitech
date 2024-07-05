/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019 [WSL: Debian]
** File description:
** my_putstr
*/

#include <unistd.h>
#include "my_exec.h"

int my_putstr(char *str)
{
    return (write(1, str, my_strlen(str)));
}