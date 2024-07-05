/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** main
*/

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "menger.h"

static int is_positive_number(const char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        if (!__builtin_isdigit(str[i]))
            return (0);
    return (1);
}

static int check_error(int argc, const char **argv)
{
    if (argc != 3)
        return (1);
    for (int i = 1; i < 3; i++)
        if (!is_positive_number(argv[i]))
            return (1);
    return (0);
}

int main(int argc, const char **argv)
{
    int size = 0;
    int levels = 0;

    if (check_error(argc, argv))
        return (84);
    size = atoi(argv[1]);
    levels = atoi(argv[2]);
    if (size % (int) pow(3, levels) != 0)
        return (84);
    menger(size, levels, 0, 0);
    return (0);
}