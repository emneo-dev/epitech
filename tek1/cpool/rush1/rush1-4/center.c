/*
** EPITECH PROJECT, 2019
** rush1-2
** File description:
** Display a layer of the square center
*/

int center(int width)
{
    for (int i = 1; i <= width; i++) {
        if (i == 1 || i == width)
            my_putchar('B');
        else
            my_putchar(' ');
    }
    return (0);
}
