/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** sh_setenv
*/

#include <unistd.h>
#include "my.h"
#include "sh.h"

static int is_a_match(char *to_search, char *env)
{
    if (!my_strncmp(to_search, env, my_strlen(to_search))
    && env[my_strlen(to_search)] == '=')
        return (1);
    return (0);
}

static result_t sh_setenv_two_arg(char **args, env_t *ep)
{
    env_t *new_node = NULL;
    env_t *origin_env = ep;

    for (; ep; ep = ep->next)
        if (is_a_match(args[0], ep->data)) {
            ep->data = append(args[0], append("=", args[1]));
            return ((result_t) {0, 0});
        }
    for (; origin_env->next; origin_env = origin_env->next);
    new_node = malloc(sizeof(env_t));
    if (!new_node)
        return ((result_t) {1, 84});
    new_node->data = append(args[0], append("=", args[1]));
    new_node->next = NULL;
    origin_env->next = new_node;
    return ((result_t) {0, 0});
}

static result_t sh_setenv_one_arg(char *arg, env_t *ep)
{
    env_t *new_node = NULL;
    env_t *origin_env = ep;

    for (; ep; ep = ep->next)
        if (is_a_match(arg, ep->data)) {
            ep->data[my_strlen(arg) + 1] = '\0';
            return ((result_t) {0, 0});
        }
    for (; origin_env->next; origin_env = origin_env->next)
    new_node = malloc(sizeof(env_t));
    if (!new_node)
        return ((result_t) {1, 84});
    new_node->data = malloc(sizeof(char) * (my_strlen(arg) + 2));
    if (!new_node->data)
        return ((result_t) {1, 84});
    my_strcpy(new_node->data, arg);
    new_node->data[my_strlen(arg)] = '=';
    new_node->data[my_strlen(arg) + 1] = '\0';
    new_node->next = NULL;
    origin_env->next = new_node;
    return ((result_t) {0, 0});
}

result_t sh_setenv(char *cmd, env_t **ep)
{
    result_t base_result = {0, 0};
    char **cmd_arr = NULL;
    int cmd_arr_len = 0;

    cmd_arr = my_str_to_word_array(cmd);
    if (!cmd_arr)
        return ((result_t) {1, 84});
    for (cmd_arr_len = 0; cmd_arr[cmd_arr_len]; cmd_arr_len++);
    switch (cmd_arr_len) {
    case 1:
        return (sh_env(cmd, ep));
    case 2:
        return (sh_setenv_one_arg(cmd_arr[1], *ep));
    case 3:
        return (sh_setenv_two_arg(cmd_arr + 1, *ep));
    default:
        my_putstr("setenv: Too many arguments.\n");
        return (base_result);
    }
}