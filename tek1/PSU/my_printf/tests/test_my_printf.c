/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** printf clone
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(my_printf, one_string_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("%S", "I like lasagnas");

    cr_assert_stdout_eq_str("I like lasagnas");
    cr_assert_eq(tmp, 15);
}

Test(my_printf, one_string_one_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("%S and pastas", "I like lasagnas");

    cr_assert_stdout_eq_str("I like lasagnas and pastas");
    cr_assert_eq(tmp, 26);
}

Test(my_printf, one_string, .init=redirect_all_stdout)
{
    int tmp = my_printf("I like lasagnas");

    cr_assert_stdout_eq_str("I like lasagnas");
    cr_assert_eq(tmp, 15);
}

Test(my_printf, one_int_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %d lasagnas", 42);

    cr_assert_stdout_eq_str("I ate 42 lasagnas");
    cr_assert_eq(tmp, 16);
}

Test(my_printf, one_percentage_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %%");

    cr_assert_stdout_eq_str("I ate %%");
    cr_assert_eq(tmp, 7);
}

Test(my_printf, one_string_flag_normal, .init=redirect_all_stdout)
{
    int tmp = my_printf("I like %s", "lasagnas");

    cr_assert_stdout_eq_str("I like lasagnas");
    cr_assert_eq(tmp, 15);
}

Test(my_printf, one_pointer_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("This is a pointer: %p", 42069);

    cr_assert_stdout_eq_str("This is a pointer: 0xa455");
    cr_assert_eq(tmp, my_strlen("This is a pointer: 0xa455"));
}

Test(my_printf, one_pointer_flag_short, .init=redirect_all_stdout)
{
    int tmp = my_printf("This is a pointer: %p", 2);

    cr_assert_stdout_eq_str("This is a pointer: 0x2");
    cr_assert_eq(tmp, my_strlen("This is a pointer: 0x2"));
}

Test(my_printf, one_char_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %c lasagna", 36);

    cr_assert_stdout_eq_str("I ate 36 lasagna");
    cr_assert_eq(tmp, my_strlen("I ate 36 lasagna"));
}

Test(my_printf, one_octal_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %o lasagna", 36);

    cr_assert_stdout_eq_str("I ate 44 lasagna");
    cr_assert_eq(tmp, my_strlen("I ate 44 lasagna"));
}

Test(my_printf, one_binary_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %b lasagna", 36);

    cr_assert_stdout_eq_str("I ate 100100 lasagna");
    cr_assert_eq(tmp, my_strlen("I ate 100100 lasagna"));
}

Test(my_printf, one_unsigned_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %u lasagna", 36);

    cr_assert_stdout_eq_str("I ate 36 lasagna");
    cr_assert_eq(tmp, my_strlen("I ate 36 lasagna"));
}

Test(my_printf, one_hexa_upper_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %X lasagna", 42069);

    cr_assert_stdout_eq_str("I ate A455 lasagna");
    cr_assert_eq(tmp, my_strlen("I ate A455 lasagna"));
}

Test(my_printf, one_hexa_lower_flag, .init=redirect_all_stdout)
{
    int tmp = my_printf("I ate %x lasagna", 42069);

    cr_assert_stdout_eq_str("I ate a455 lasagna");
    cr_assert_eq(tmp, my_strlen("I ate a455 lasagna"));
}
