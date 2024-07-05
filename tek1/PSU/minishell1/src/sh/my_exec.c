/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exec
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"
#include "sh.h"

static void launch_child(int parent_id, int *child_id, char **args, char **envp)
{
    *child_id = fork();
    if (parent_id != getpid())
        if (execve(args[0], args, envp) == -1)
            exit(84);
}

result_t my_exec(char **cmd, char **envp)
{
    int parent_pid = getpid();
    int child_pid = 0;
    int child_status = 0;
    int something_went_wrong = 0;

    launch_child(parent_pid, &child_pid, cmd, envp);
    waitpid(child_pid, &child_status, 0);
    if (WTERMSIG(child_status)) {
        my_putstr(strsignal(WTERMSIG(child_status)));
        something_went_wrong = 1;
    }
    if (WCOREDUMP(child_status)) {
        my_putstr(" (Core dumped)");
        something_went_wrong = 1;
    }
    if (something_went_wrong)
        write(1, "\n", 1);
    return ((result_t) {0, 0});
}