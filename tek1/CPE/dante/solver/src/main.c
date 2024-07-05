/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Main file
*/

#include <stdio.h>
#include "prototype.h"

int main(int argc, char const **argv)
{
    if (argc != 2) {
        dprintf(2, "\e[1;31m[FATAL]\e[0m: Not the good amount of arguments\n");
        return (84);
    }
    return (solver(argv));
}