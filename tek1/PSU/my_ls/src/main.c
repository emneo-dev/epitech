/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** main
*/

#include "my.h"
#include "ls.h"

int main(int argc, char const **argv)
{
    if (argc > 1 &&
    (!my_strcmp("-h", argv[1]) || !my_strcmp("--help", argv[1])))
        return (helper());
    return (my_ls(argc, argv));
}