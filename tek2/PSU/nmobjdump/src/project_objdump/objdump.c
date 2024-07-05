/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** objdump
*/

#include <stdio.h>
#include <stdbool.h>

#include "objdump.h"

static int print_file(const char *filename, const char *call)
{
    file_t file;

    if (load_file_in_memory(&file, filename, call))
        return 84;
    switch (check_arch(&file)) {
    case arch_64:
        print_sections_64(&file, filename, call);
        return 0;
    case arch_32:
        print_sections_32(&file, filename, call);
        return 0;
    }
    fprintf(stderr, "%s: %s: file format not recognized\n", call, filename);
    return 84;
}

int objdump(int argc, char **argv)
{
    int return_value = 0;

    if (argc == 1)
        return print_file("a.out", argv[0]);
    else if (argc == 2)
        return print_file(argv[1], argv[0]);
    for (int i = 1; i < argc; i++) {
        if (return_value)
            print_file(argv[i], argv[0]);
        else
            return_value = print_file(argv[i], argv[0]);
    }
    return return_value;
}