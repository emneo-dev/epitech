/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** handle_cmd
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "ftp.h"

static const cmd_suffix_t CMD_SUFFIX_MAP[14] = {
    {"USER", exec_cmd_user},
    {"PASS", exec_cmd_pass},
    {"CWD" , exec_cmd_cwd},
    {"CDUP", exec_cmd_cwd},
    {"QUIT", exec_cmd_quit},
    {"DELE", exec_cmd_dele},
    {"PWD" , exec_cmd_pwd},
    {"PASV", exec_cmd_pasv},
    {"PORT", exec_cmd_port},
    {"HELP", exec_cmd_help},
    {"NOOP", exec_cmd_noop},
    {"RETR", exec_cmd_retr},
    {"STOR", exec_cmd_stor},
    {"LIST", exec_cmd_list}
};

static cmd_function_t get_cmd_function(const char *cmd_suffix)
{
    for (size_t i = 0; i < 14; ++i)
        if (!strcasecmp(cmd_suffix, CMD_SUFFIX_MAP[i].suffix))
            return CMD_SUFFIX_MAP[i].fun_ptr;
    return exec_cmd_unknown;
}

static int exec_cmd(char **cmd, server_t *srv, client_t *client)
{
    cmd_function_t cmd_func = NULL;

    if (!cmd[0])
        return -1;
    cmd_func = get_cmd_function(cmd[0]);
    if (cmd_func != exec_cmd_unknown)
        fprintf(stdout, "%s - Execution command with suffix %s\n",
            get_client_string(client), cmd[0]);
    return cmd_func(cmd, srv, client);
}

int exec_raw_cmd(char *cmd, server_t *srv, client_t *client)
{
    char *buffer[3] = {0};
    const char *delim = " ";

    buffer[0] = strtok(cmd, delim);
    buffer[1] = strtok(NULL, delim);
    return exec_cmd(buffer, srv, client);
}