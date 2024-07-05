/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** Some desc
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb >= 13)
        return (0);
    return (recur(nb, 1, 1));
}

int recur(int nb, int i, int result)
{
    if (i > nb)
        return (result);
    result *= i;
    return (recur(nb, i + 1, result));
}
