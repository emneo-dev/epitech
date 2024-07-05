/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** tab_to_2dtab
*/

#include <stdlib.h>
#include <stdio.h>

static int **init_tab(int length, int width)
{
    int **res = malloc(sizeof(int*) * (length + 1));

    res[length] = NULL;
    for (int i = 0; i < length; i++)
        res[i] = malloc(sizeof(int) * width);
    return res;
}

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **result = init_tab(length, width);

    for (int i = 0; i < length; i++)
        for (int y = 0; y < width; y++)
            result[i][y] = tab[y + i * width];
    *res = result;
}