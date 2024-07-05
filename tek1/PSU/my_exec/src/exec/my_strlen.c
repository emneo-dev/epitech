/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019 [WSL: Debian]
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}