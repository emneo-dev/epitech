/*
** EPITECH PROJECT, 2019
** rush1-4
** File description:
** Display base of square
*/

int base(int width)
{
    for (int i = 1; i <= width; i++){
        if (i == 1)
            my_putchar('A');
        else if (i == width)
            my_putchar('C');
        else
            my_putchar('B');
    }
    return (0);
}
