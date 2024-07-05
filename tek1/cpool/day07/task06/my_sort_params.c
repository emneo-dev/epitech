/*
** EPITECH PROJECT, 2019
** my_sort_params
** File description:
** Some desc
*/

#include <my.h>

int main(int argc, char *argv[])
{
    char *tmp;
    int h = 1;

    for (int i = 0; h == 1; ++i) {
        h = 0;
        for (int z = 0; z < argc - 1; z++) {
            if (my_strcmp(argv[z], argv[z + 1]) > 0) {
                tmp = argv[z];
                argv[z] = argv[z + 1];
                argv[z + 1] = tmp;
                h = 1;
            }
        }
    }
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return 0;
}