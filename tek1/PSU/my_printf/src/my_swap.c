/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Swap two integers
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
