/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** print_help
*/

#include <stdio.h>

void print_help(const char *executable_name)
{
    printf("USAGE: %s port path\n"
        "\tport  is the port number on which the server socket listens\n"
        "\tpath  is the path to the home directory for the Anonymous user\n",
        executable_name);
}