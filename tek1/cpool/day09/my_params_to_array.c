/*
** EPITECH PROJECT, 2019
** my_params_to_array
** File description:
** Some desc
*/

#include <my.h>
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    int tmp;
    struct info_param *array = (malloc(sizeof(struct info_param) * (ac + 1)));
    for (int i = 0; i < ac; i++) {
        array[i].length = my_strlen(av[i]);
        array[i].str = av[i];
        array[i].copy = my_strdup(av[i]);
        array[i].word_array = my_str_to_word_array(av[i]);
        tmp = i;
    }
    return (array);
}
