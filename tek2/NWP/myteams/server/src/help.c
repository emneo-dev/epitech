/*
** EPITECH PROJECT, 2021
** my_teams
** File description:
** help
*/

#include <stdio.h>

void display_help(const char *executable_name)
{
    printf("USAGE: %s port\n\n"
        "\tport\tis the port number on which the server socket listens\n",
        executable_name);
}