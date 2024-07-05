/*
** EPITECH PROJECT, 2019
** rush1-2
** File description:
** Display base of square
*/

int base(int width)
{
    for (int i = 1; i <= width; i++){
        if (i == 1)
            my_putchar('/');
        else if (i == width)
            my_putchar('\\');
        else
            my_putchar('*');
    }
    return (0);
}
