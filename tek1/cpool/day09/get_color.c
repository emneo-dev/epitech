/*
** EPITECH PROJECT, 2019
** get_color
** File description:
** Some desc
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int clr = 0;

    clr |= red;
    clr = clr << 8;
    clr |= green;
    clr = clr << 8;
    clr |= blue;
    return (clr);
}