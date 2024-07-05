/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** r_carriage
*/

void r_carriage(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
}