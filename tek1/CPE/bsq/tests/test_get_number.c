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

Test(get_number, one_digit_number, .timeout=1)
{
    int fd = open("tests/test_files/number_1_digit", O_RDONLY);
    cr_assert(fd != -1);
    fnb_t ret = get_number(fd);
    close(fd);
    cr_assert_eq(ret.length, 1);
    cr_assert_eq(ret.number, 8);
}

Test(get_number, two_digits_number, .timeout=1)
{
    int fd = open("tests/test_files/number_2_digits", O_RDONLY);
    cr_assert(fd != -1);
    fnb_t ret = get_number(fd);
    close(fd);
    cr_assert_eq(ret.length, 2);
    cr_assert_eq(ret.number, 42);
}
