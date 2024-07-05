/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** Some desc
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb >= 13)
        return (0);
    for (int i = 1; i <= nb; i++) {
        result *= i;
    }
    return (result);
}
