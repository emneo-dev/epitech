/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Return the sum a 1d array of ints
*/

int array_1d_sum(int const *arr, int size)
{
    char cr = '\n';
    int ret = 0;

    for (int i = 0; i < size; i++)
        ret += arr[i];
    return (ret);
}
