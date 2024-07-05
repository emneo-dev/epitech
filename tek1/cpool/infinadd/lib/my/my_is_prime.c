/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Return wether or not the given int is prime
*/

int my_is_prime(int nb)
{
    float nnb = nb;

    if (nb <= 2 || nb % 2 == 0)
        return (0);
    for (int i = 3; i < nb; i += 2) {
        if ((nnb / 2) == ((int)(nnb / 2)))
            return (0);
        return (1);
    }
}
