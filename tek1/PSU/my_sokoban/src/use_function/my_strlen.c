/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;
    for (i = 0; str[i]; i++);
    return (i);
}