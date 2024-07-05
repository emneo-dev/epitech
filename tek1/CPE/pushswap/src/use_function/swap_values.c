/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** swap_values
*/

void swap_values(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}