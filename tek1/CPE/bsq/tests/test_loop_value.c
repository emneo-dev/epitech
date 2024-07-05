/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Test for the loop_value function
*/

#include <criterion/criterion.h>
#include <bsq.h>
#include <unistd.h>

Test(loop_value, easy_loop, .timeout=1)
{
    map_t mem = load_file_to_mem("tests/mouli_maps/intermediate_map_100_100");
    loop_value(&mem);
    cr_assert(1);
}
