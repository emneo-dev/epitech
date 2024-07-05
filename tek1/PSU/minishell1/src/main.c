/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** main
*/

#include <unistd.h>
#include "my.h"
#include "sh.h"

int main(int ac, char **av, char **ep)
{
    if (!isatty(0))
        return (handle_incoming_pipe(ep));
    (void)ac;
    (void)av;
    return (sh(ep));
}