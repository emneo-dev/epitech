/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Some desc
*/

int recur2(int nb, int p, int rec, int result);

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (recur2(nb, p, 0, nb));
}

int recur2(int nb, int p, int rec, int result)
{
    if (rec < p - 1) {
        int tmp = result;
        result = result * nb;
        if ((result < 0) != (tmp < 0) && nb >= 0) {
            return (0);
        }
        else if ((result > 0) != (tmp < 0) && nb < 0) {
            return (0);
        }
        else {
            return (recur2(nb, p, rec + 1, result));
        }
    }
    return (result);
}
