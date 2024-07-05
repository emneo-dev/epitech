/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** Some desc
*/

int my_strlen(char const *str);
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int length = 0;
    char *str;
    char *str_old;

    for (int i = 0; i < argc; i++)
        length += my_strlen(argv[i]) + 1;
    str = malloc(sizeof(char) * length);
    str_old = str;
    for (int i = 0; i < argc; i++){
        for (int z = 0; argv[i][z] != '\0'; z++)
            str[z] = argv[i][z];
        str += my_strlen(argv[i]);
        str[0] = '\n';
        str++;
    }
    return (str_old);
}