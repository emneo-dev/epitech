/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Print a 1d array
*/

void array_1d_print_chars(char const *arr)
{
    char cr = '\n';

    for (int i = 0; arr[i]; i++) {
        write(1, &(arr[i]), 1);
        write(1, &cr, 1);
    }
}
