/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Return the shortest of the three given number
*/

char get_shortest(char a, char b, char c)
{
    if (a <= b && a <= c)
        return (a);
    else if (b <= a && b <= c)
        return (b);
    else
        return (c);
}
