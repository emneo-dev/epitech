/*
** EPITECH PROJECT, 2019
** rush1-1
** File description:
** Some desc
*/

int base(int width)
{
    for (int i = 1; i <= width; i++){
        if (i == 1)
            my_putchar('o');
        else if (i == width)
            my_putchar('o');
        else
            my_putchar('-');
    }
    return (0);
}
