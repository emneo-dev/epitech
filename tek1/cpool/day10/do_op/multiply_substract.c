/*
** EPITECH PROJECT, 2019
** CPool_Day10_2019
** File description:
** Complementary file for do-op
*/

int do_multiply(int const a, int const b)
{
    if (a > 2147483647 / b) {
        my_putchar('0');
        return (84);
    }
    my_put_nbr((long)(a * b));
    return (0);
}

int do_substract(int const a, int const b)
{
    if (a < -2147483648 + b) {
        my_putchar('0');
        return (84);
    }
    my_put_nbr((long)(a - b));
    return (0);
}
