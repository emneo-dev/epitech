/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** sh_exit
*/

#include "my.h"
#include "sh.h"

static int error_handling(char **arr)
{
    int status_len = 0;

    status_len = my_strlen(arr[1]);
    if (status_len > 1 && (arr[1][0] == '-' ||
        (arr[1][0] >= '0' && arr[1][0] <= '9')) && !my_str_isnum(arr[1] + 1)) {
        my_putstr("exit: Badly formed number.\n");
        return (1);
    } else if (!my_str_isnum(arr[1]) && arr[1][0] != '-') {
        my_putstr("exit: Expression Syntax.\n");
        return (1);
    }
    return (0);
}

result_t sh_exit(char *cmd, env_t **ep)
{
    char **arr = NULL;
    int arr_len = 0;
    (void)ep;

    arr = my_str_to_word_array(cmd);
    for (; arr[arr_len]; arr_len++);
    if (arr_len == 2) {
        if (error_handling(arr))
            return ((result_t) {0, 0});
        return ((result_t) {1, my_getnbr(arr[1])});
    } else if (arr_len == 1)
        return ((result_t) {1, 0});
    my_putstr("exit: Expression Syntax.\n");
    return ((result_t) {0, 0});
}