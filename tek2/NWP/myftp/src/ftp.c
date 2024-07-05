/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** ftp
*/

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>

#include "ftp.h"

static void onshutdown(int unused)
{
    UNUSED(unused);
    printf("Shutting down...\n");
    exit(84);
}

static bool check_port_validity(const char *port)
{
    const int length = strlen(port);

    for (size_t i = 0; port[i]; ++i)
        if (!isdigit(port[i]))
            return false;
    if (length > 5)
        return false;
    else if (length < 5)
        return true;
    return strncmp(port, "65535", length) <= 0;
}

int main(int argc, const char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-help")) {
        print_help(argv[0]);
        return 0;
    } else if (argc == 3) {
        if (!check_port_validity(argv[1]))
            return 84;
        signal(SIGINT, onshutdown);
        return launch_server(atoi(argv[1]), argv[2]);
    }
    print_help(argv[0]);
    return 84;
}