/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Some desc
*/

int my_putchar(char);

static int print_nbr(int isNegative, long nb)
{
    int i;
    int hasStarted = 0;
    int tmp;

    if (nb == 0 ) {
        my_putchar('0');
        return (0);
    }

    if (isNegative == 1 )
        my_putchar('-');
    for (i = 1000000000; i >= 1; i = i / 10) {
        tmp = (nb / i) - ((nb % i) / i );
        hasStarted = (tmp == 0) ? hasStarted : 1;
        if (hasStarted == 1) {
            my_putchar('0' + tmp);
            nb = nb - tmp * i;
        }
    }
    return (0);
}

int my_put_nbr(int nb)
{
    int isNegative;

    isNegative = (nb < 0) ? 1 : 0;
    if (isNegative == 1 )
        nb = nb * (-1);
    print_nbr(isNegative, nb);
    return (0);
}
