/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** test_sample
*/

#include <stdio.h>
#include <dirent.h>
#include <criterion/criterion.h>
#include "struct.h"
#include "prototype.h"

Test(sample, normal_call, .timeout = 1)
{
    int return_value = 0;
    int ac = 1;
    char *av[1] = {"./sample_output"};

    return_value = tetris(ac, av);
    cr_assert_eq(return_value, 0);
}
