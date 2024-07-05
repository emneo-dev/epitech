/*
** EPITECH PROJECT, 2019
** generator
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "struct.h"
#include "prototype.h"
#include "my.h"

void redirect_all_std(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

// CHECK ARGUMENT

Test(check_argument, TEST_AC_EQ_4, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    int ac = 4;
    char *av[4] = {"./sample_output", "5", "5", "perfect"};

    return_value = check_argument(ac, av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument, TEST_AC_EQ_3, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    int ac = 3;
    char *av[3] = {"./sample_output", "5", "5"};

    return_value = check_argument(ac, av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument, TEST_AC_EQ_5, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    int ac = 5;
    char *av[5] = {"./sample_output", "ui", "5", "5", "perfect"};

    return_value = check_argument(ac, av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument, TEST_AC_EQ_2, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    int ac = 2;
    char *av[2] = {"./sample_output", "5"};

    return_value = check_argument(ac, av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

// CHECK AGUMENT PERFECT

Test(check_argument_perfect, TEST_AV1_EQ_5_AV2_EQ_5_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "5", "5", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument_perfect, TEST_AV1_EQ_1_AV2_EQ_5_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "1", "5", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument_perfect, TEST_AV1_EQ_5_AV2_EQ_1_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "5", "1", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument_perfect, TEST_AV1_EQ_5_AV2_EQ_5_AV3_EQ_perf, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "5", "5", "perf"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_perfect, TEST_AV1_EQ_a_AV2_EQ_5_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "a", "5", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_perfect, TEST_AV1_EQ_4a_AV2_EQ_5_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "4a", "5", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_perfect, TEST_AV1_EQ_6_AV2_EQ_a_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "6", "a", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_perfect, TEST_AV1_EQ_4_AV2_EQ_5a_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "4", "5a", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_perfect, TEST_AV1_EQ_NEG_5_AV2_EQ_5_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "-5", "5", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_perfect, TEST_AV1_EQ_5_AV2_EQ_NEG_5_AV3_EQ_perfect,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "5", "-5", "perfect"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_perfect, TEST_AV1_EQ_5_AV2_EQ_5_AV3_EQ_perf3ct,
.timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[4] = {"./sample_output", "5", "5", "perf3ct"};

    return_value = check_argument_perfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

// CHECK ARGUMENT IMPERFECT

Test(check_argument_imperfect, TEST_AV1_EQ_5_AV2_EQ_5, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "5", "5"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument_imperfect, TEST_AV1_EQ_1_AV2_EQ_5, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "1", "5"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument_imperfect, TEST_AV1_EQ_5_AV2_EQ_1, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "5", "1"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 0);
}

Test(check_argument_imperfect, TEST_AV1_EQ_a_AV2_EQ_5, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "a", "5"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_imperfect, TEST_AV1_EQ_4a_AV2_EQ_5, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "4a", "5"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_imperfect, TEST_AV1_EQ_6_AV2_EQ_a, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "6", "a"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_imperfect, TEST_AV1_EQ_4_AV2_EQ_5a, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "4", "5a"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_imperfect, TEST_AV1_EQ_NEG_5_AV2_EQ_5, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "-5", "5"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

Test(check_argument_imperfect, TEST_AV1_EQ_5_AV2_EQ_NEG_5, .timeout = 1)
{
    int return_value = 0;
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return_value = 84;
    char *av[3] = {"./sample_output", "5", "-5"};

    return_value = check_argument_imperfect(av, generator_o);
    free(generator_o);
    cr_assert_eq(return_value, 1);
}

// MY STR ISNUM

Test(my_str_isnum, TEST_STR_EQ_5, .timeout = 1)
{
    int return_value = 0;
    char *str = "5";

    return_value = my_str_isnum(str);
    cr_assert_eq(return_value, 0);
}

Test(my_str_isnum, TEST_STR_EQ_NEG_5, .timeout = 1)
{
    int return_value = 0;
    char *str = "-5";

    return_value = my_str_isnum(str);
    cr_assert_eq(return_value, 1);
}

Test(my_str_isnum, TEST_STR_EQ_y, .timeout = 1)
{
    int return_value = 0;
    char *str = "y";

    return_value = my_str_isnum(str);
    cr_assert_eq(return_value, 1);
}

Test(my_str_isnum, TEST_STR_EQ_6y, .timeout = 1)
{
    int return_value = 0;
    char *str = "6y";

    return_value = my_str_isnum(str);
    cr_assert_eq(return_value, 1);
}

Test(my_str_isnum, TEST_STR_EQ_BACK_SLASH_n, .timeout = 1)
{
    int return_value = 0;
    char *str = "\n";

    return_value = my_str_isnum(str);
    cr_assert_eq(return_value, 1);
}

// MY GETNBR

Test(my_getnbr, TEST_STR_EQ_5, .timeout = 1)
{
    int return_value = 0;
    char *str = "5";

    return_value = my_getnbr(str);
    cr_assert_eq(return_value, 5);
}

Test(my_getnbr, TEST_STR_EQ_NEG_5, .timeout = 1)
{
    int return_value = 0;
    char *str = "-5";

    return_value = my_getnbr(str);
    cr_assert_eq(return_value, -5);
}

Test(my_getnbr, TEST_STR_EQ_a, .timeout = 1)
{
    int return_value = 0;
    char *str = "a";

    return_value = my_getnbr(str);
    cr_assert_eq(return_value, NULL);
}

// MY STRCMP

Test(my_strcmp, TEST_STR1_EQ_HELLO_STR2_EQ_HELLO, .timeout = 1)
{
    int return_value = 0;
    char *str1 = "Hello";
    char *str2 = "Hello";

    return_value = my_strcmp(str1, str2);
    cr_assert_eq(return_value, 0);
}

Test(my_strcmp, TEST_STR1_EQ_HELO_STR2_EQ_HELLO, .timeout = 1)
{
    int return_value = 0;
    char *str1 = "Helo";
    char *str2 = "Hello";

    return_value = my_strcmp(str1, str2);
    cr_assert_eq(return_value, 1);
}

