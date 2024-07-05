/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** Some desc
*/

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    for (int i = 0; i < p - 1; ++i) {
        int tmp = result;
        result = result * nb;
        if ((result < 0) != (tmp < 0) && nb >= 0) {
            return (0);
        }
        else if ((result > 0) != (tmp < 0) && nb < 0) {
            return (0);
        }
    }
    return (result);
}
