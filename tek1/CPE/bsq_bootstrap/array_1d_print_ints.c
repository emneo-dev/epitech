/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Print a 1d array of ints
*/

void array_1d_print_ints(int const *arr, int size)
{
    char cr = '\n';

    for (int i = 0; i < size; i++) {
        my_put_nbr(arr[i]);
        write(1, &cr, 1);
    }
}
