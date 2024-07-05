/*
** EPITECH PROJECT, 2020
** PSU_my_ls_bootstrap_2019
** File description:
** main
*/

#include "info_file.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    return (info_file(argv[1]));
}