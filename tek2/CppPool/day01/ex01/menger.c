/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** menger
*/

#include <stdio.h>

static void print_hole(int size, int x, int y)
{
    printf("%03d %03d %03d\n", size, x, y);
}

// Don't mind the big return
// IT. JUST. WORKS.
int menger(int size, int levels, int x, int y)
{
    if (!levels)
        return (0);
    print_hole(size / 3, size / 3 + x, size / 3 + y);
    return (
        menger(size / 3, levels - 1, x, y) ||
        menger(size / 3, levels - 1, x, y + size / 3) ||
        menger(size / 3, levels - 1, x, y + (size / 3) * 2) ||
        menger(size / 3, levels - 1, x + size / 3, y) ||
        menger(size / 3, levels - 1, x + size / 3, y + (size / 3) * 2) ||
        menger(size / 3, levels - 1, x + (size / 3) * 2, y) ||
        menger(size / 3, levels - 1, x + (size / 3) * 2, y + size / 3) ||
        menger(size / 3, levels - 1, x + (size / 3) * 2, y + (size / 3) * 2)
    );
}