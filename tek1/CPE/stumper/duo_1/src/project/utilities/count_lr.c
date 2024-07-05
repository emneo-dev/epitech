/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** count_lr
*/

int count_lr(char const *str)
{
    int nb = 0;

    if (!str)
        return (0);
    for (int i = 0; str[i]; i++)
        nb = (str[i] == '\n') ? nb + 1 : nb;
    return (nb);
}
