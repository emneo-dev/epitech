/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main
*/

#include "my.h"
#include "my_runner.h"

int main(int argc, char const **argv)
{
    if (argc != 2)
        return (84);
    if (!my_strcmp(argv[1], "-h"))
        return (helper());
    return (my_runner(argv));
}