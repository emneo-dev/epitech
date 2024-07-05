/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Some desc
*/

int my_putchar(char);

void my_put_float(float nb)
{
    int tmp = (int)(nb);
    my_put_nbr(tmp);
    my_putchar('.');
    tmp = (int)((nb - tmp) * 100);
    my_put_nbr(tmp);
}