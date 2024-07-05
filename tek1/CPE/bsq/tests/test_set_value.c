/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Test for the set_value function
*/

#include <criterion/criterion.h>
#include <bsq.h>
#include <stdio.h>

Test(my_set_value, normal_set, .timeout=1)
{
    map_t mem;
    mem.mem = malloc(sizeof(char) * 10);
    mem.columns = 2;
    mem.mem[3] = 2;
    mem.mem[0] = 1;
    mem.mem[1] = 4;
    my_set_value(&mem, 4);
    cr_assert_eq(mem.mem[4], 2);
    free(mem.mem);
}

Test(my_set_value, set_on_left, .timeout=1)
{
    map_t mem;
    mem.mem = malloc(sizeof(char) * 10);
    mem.columns = 2;
    mem.mem[0] = 6;
    mem.mem[3] = '.';
    my_set_value(&mem, 3);
    cr_assert_eq(mem.mem[3], 1);
    free(mem.mem);
}

Test(my_set_value, set_on_round, .timeout=1)
{
    map_t mem;
    mem.mem = malloc(sizeof(char) * 10);
    mem.columns = 2;
    mem.mem[0] = 6;
    mem.mem[3] = 'o';
    my_set_value(&mem, 3);
    cr_assert_eq(mem.mem[3], 0);
    free(mem.mem);
}
