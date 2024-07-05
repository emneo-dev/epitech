/*
** EPITECH PROJECT, 2020
** PSU_tetris
** File description:
** change_carriage
*/

void change_carriage(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
}