/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Test file for the BSQ project
*/

#include <criterion/criterion.h>
#include <bsq.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

Test(load_file_to_mem, 34_137_load, .timeout=1)
{
    map_t ret = load_file_to_mem(
                "tests/mouli_maps/intermediate_map_34_137_filled");
    cr_assert_eq(ret.columns, 34);
    cr_assert_eq(ret.row, 137);
}

Test(load_file_to_mem, 2000_2000_load, .timeout=1)
{
    map_t ret = load_file_to_mem("tests/mouli_maps/intermediate_map_2000_2000");
    cr_assert_eq(ret.columns,2000);
    cr_assert_eq(ret.row, 2000);
}
