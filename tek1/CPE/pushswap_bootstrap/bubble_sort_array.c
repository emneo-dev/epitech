/*
** EPITECH PROJECT, 2019
** pushswap_bootstrap
** File description:
** Sort the given array
*/

#include <pushswap_bs.h>

static int is_sorted(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i)
        if (array[i] > array[i + 1])
            return (0);
    return (1);
}

static void sort_list(int *array, int size)
{
    for (int z = 0; z < size - 1; z++)
        if (array[z] > array[z + 1])
            swap_elem(array, z, z + 1);
    return;
}

void bubble_sort_array(int *array, int size)
{
    while (!(is_sorted(array, size)))
        sort_list(array, size);
    return;
}
