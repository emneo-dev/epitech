/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Return wether or not the given int is prime
*/

int my_is_prime(int nb)
{
    if (nb <= 2 || nb % 2 == 0)
        return (0);
    for (float nnb = 3; nnb < nb; nnb += 2)
        if ((nb / nnb) == ((int)(nb / nnb)))
            return (0);
    return (1);
}
