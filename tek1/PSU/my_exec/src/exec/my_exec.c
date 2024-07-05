/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019 [WSL: Debian]
** File description:
** my_exec
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "my_exec.h"

static void destroy_array(char **arr)
{
    char **original_arr = arr;
    for (; *arr; (*arr)++)
        free(*arr);
    free(original_arr);
}

static int my_str_array_len(char **arr_str)
{
    int i = 0;

    for (i = 0; arr_str[i]; i++);
    return (i);
}

static void launch_child(int parent_id, int child_id, char **args, char **envp)
{
    child_id = fork();
    if (parent_id == getpid()) {
        my_putstr("\nChild PID: ");
        my_put_nbr(child_id);
        write(1, "\n", 1);
    }
    else
        if (execve(args[0], args, envp) == -1)
            exit(0);
}

static void print_infos(char **arguments, char **envp)
{
    int parent_pid = getpid();
    int child_pid = 0;
    int child_status = 0;

    my_putstr("Program name: ");
    my_putstr(arguments[0]);
    my_putstr("\nNb args: ");
    my_put_nbr(my_str_array_len(arguments) - 1);
    my_putstr("\nPID: ");
    my_put_nbr(parent_pid);
    launch_child(parent_pid, child_pid, arguments, envp);
    waitpid(child_pid, &child_status, 0);
    my_putstr("Program terminated.\n");
    my_putstr("Status: ");
    if (WTERMSIG(child_status))
        my_putstr(strsignal(WTERMSIG(child_status)));
    else
        my_putstr("OK");
    write(1, "\n", 1);
    return;
}

int my_exec(int argc, char **argv, char **envp)
{
    char **arguments = NULL;

    if (argc != 2)
        return (84);
    arguments = str_to_word_array(argv[1]);
    if (!arguments || !*arguments)
        return (84);
    print_infos(arguments, envp);
    destroy_array(arguments);
    return (0);
}
