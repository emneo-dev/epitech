/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** put_str
*/

#include "sokoban.h"
#include <unistd.h>

int put_str(char *str)
{
    int i = my_strlen(str);
    write(1, str, i);
    return (i);
}