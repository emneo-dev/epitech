/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Some desc
*/

char *my_charlowcase(char str)
{
    if (str >= 65 && str <= 90)
        str += 32;
    return (str);
}