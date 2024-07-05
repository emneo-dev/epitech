/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    for (i = 0; str[i]; i-=-1);
    return (i);
}

static char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!new_str)
        return (NULL);
    for (int i = 0; i < my_strlen(str); ++i)
        new_str[i] = str[i];
    return (new_str);
}

static int contains_new_line(char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; ++i)
        if (str[i] == '\n') {
            str[i] = '\0';
            return (1);
        }
    return (0);
}

static int append(char **final_buff, char *new_buff)
{
    int len_final_buff = 0;
    int len_new_buff = my_strlen(new_buff);
    char *ret_buff = NULL;

    if (!(*final_buff)) {
        *final_buff = malloc(sizeof(char) * (len_new_buff + 1));
        if (!(*final_buff))
            return (-1);
        for (int i = 0; i <= len_new_buff; (*final_buff)[i] = new_buff[i], i++);
        return (0);
    }
    len_final_buff = my_strlen(*final_buff);
    ret_buff = malloc(sizeof(char) * (len_final_buff + len_new_buff + 1));
    if (!ret_buff)
        return (-1);
    for (int i = 0; i < len_final_buff; ret_buff[i] = (*final_buff)[i], i++);
    for (int i = 0; i < len_new_buff;
        ret_buff[len_final_buff + i] = new_buff[i], i++);
    ret_buff[len_final_buff + len_new_buff] = '\0';
    *final_buff = ret_buff;
    return (0);
}

char *get_next_line(int fd)
{
    static char *final_buff = NULL;
    char quick_buff[READ_SIZE + 1];
    int ret = 1;
    int len_ret = 0;
    char *to_return = NULL;

    while (!(contains_new_line(final_buff)) && ret) {
        for (int i = 0; i <= READ_SIZE; quick_buff[i] = '\0', ++i);
        ret = read(fd, quick_buff, READ_SIZE);
        if (append(&final_buff, quick_buff) == -1)
            return (NULL);
    }
    if (!(ret) && !(*final_buff))
        return (NULL);
    to_return = my_strdup(final_buff);
    if (!(ret)) {
        final_buff = NULL;
        return (to_return);
    }
    final_buff += my_strlen(final_buff) + 1;
    return (to_return);
}