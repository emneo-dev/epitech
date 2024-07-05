/*
** EPITECH PROJECT, 2019
** pushswap_bootstrap
** File description:
** Swap two elements
*/

void swap_elem(int *array, int index1, int index2)
{
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
    return;
}
