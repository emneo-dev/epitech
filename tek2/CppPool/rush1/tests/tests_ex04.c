/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush1-mathias.ressort [SSH: 192.168.0.19]
** File description:
** tests_ex04
*/

#include <criterion/criterion.h>
#include <signal.h>

#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"

TestSuite(ex04, .timeout=1);

// Int

Test(ex04, base_int_addition)
{
    Object *obj_1 = new(Int, 1);
    Object *obj_2 = new(Int, 4);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = addition(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Int (5)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_int_subtraction)
{
    Object *obj_1 = new(Int, 1);
    Object *obj_2 = new(Int, 4);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = subtraction(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Int (-3)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_int_multiplication)
{
    Object *obj_1 = new(Int, 1);
    Object *obj_2 = new(Int, 4);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = multiplication(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Int (4)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_int_division)
{
    Object *obj_1 = new(Int, 8);
    Object *obj_2 = new(Int, 4);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = division(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Int (2)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_int_equal)
{
    Object *obj_1 = new(Int, 4);
    Object *obj_2 = new(Int, 4);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = eq(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_int_not_equal)
{
    Object *obj_1 = new(Int, 4);
    Object *obj_2 = new(Int, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = eq(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_int_lesser_than)
{
    Object *obj_1 = new(Int, 4);
    Object *obj_2 = new(Int, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_int_not_lesser_than_equal)
{
    Object *obj_1 = new(Int, 5);
    Object *obj_2 = new(Int, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_int_not_lesser_than)
{
    Object *obj_1 = new(Int, 5);
    Object *obj_2 = new(Int, 4);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_int_greater_than)
{
    Object *obj_1 = new(Int, 5);
    Object *obj_2 = new(Int, 4);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_int_not_greater_than_equal)
{
    Object *obj_1 = new(Int, 5);
    Object *obj_2 = new(Int, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_int_not_greater_than)
{
    Object *obj_1 = new(Int, 4);
    Object *obj_2 = new(Int, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

// -------------------------
// Float
// -------------------------

Test(ex04, base_float_addition)
{
    Object *obj_1 = new(Float, 1.0f);
    Object *obj_2 = new(Float, 4.0f);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = addition(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Float (5.000000)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_float_subtraction)
{
    Object *obj_1 = new(Float, 1.0f);
    Object *obj_2 = new(Float, 4.0f);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = subtraction(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Float (-3.000000)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_float_multiplication)
{
    Object *obj_1 = new(Float, 1.0f);
    Object *obj_2 = new(Float, 4.0f);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = multiplication(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Float (4.000000)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_float_division)
{
    Object *obj_1 = new(Float, 8.0f);
    Object *obj_2 = new(Float, 4.0f);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = division(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Float (2.000000)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_float_equal)
{
    Object *obj_1 = new(Float, 4.0f);
    Object *obj_2 = new(Float, 4.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = eq(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_float_not_equal)
{
    Object *obj_1 = new(Float, 4.0f);
    Object *obj_2 = new(Float, 5.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = eq(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_float_lesser_than)
{
    Object *obj_1 = new(Float, 4.0f);
    Object *obj_2 = new(Float, 5.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_float_not_lesser_than_equal)
{
    Object *obj_1 = new(Float, 5.0f);
    Object *obj_2 = new(Float, 5.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_float_not_lesser_than)
{
    Object *obj_1 = new(Float, 5.0f);
    Object *obj_2 = new(Float, 4.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_float_greater_than)
{
    Object *obj_1 = new(Float, 5.0f);
    Object *obj_2 = new(Float, 4.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_float_not_greater_than_equal)
{
    Object *obj_1 = new(Float, 5.0f);
    Object *obj_2 = new(Float, 5.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_float_not_greater_than)
{
    Object *obj_1 = new(Float, 4.0f);
    Object *obj_2 = new(Float, 5.0f);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

// -------------------------
// Char
// -------------------------

Test(ex04, base_char_addition)
{
    Object *obj_1 = new(Char, 36);
    Object *obj_2 = new(Char, 6);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = addition(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Char (*)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_char_subtraction)
{
    Object *obj_1 = new(Char, 50);
    Object *obj_2 = new(Char, 8);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = subtraction(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Char (*)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_char_multiplication)
{
    Object *obj_1 = new(Char, 6);
    Object *obj_2 = new(Char, 7);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = multiplication(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Char (*)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_char_division)
{
    Object *obj_1 = new(Char, 84);
    Object *obj_2 = new(Char, 2);
    Object *obj_result = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    obj_result = division(obj_1, obj_2);
    cr_assert_not_null(obj_result);
    obj_str = str(obj_result);
    cr_assert_str_eq(obj_str, "<Char (*)>");
    free(obj_str);
    delete(obj_1);
    delete(obj_2);
    delete(obj_result);
}

Test(ex04, base_char_equal)
{
    Object *obj_1 = new(Char, 4);
    Object *obj_2 = new(Char, 4);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = eq(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_char_not_equal)
{
    Object *obj_1 = new(Char, 4);
    Object *obj_2 = new(Char, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = eq(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_char_lesser_than)
{
    Object *obj_1 = new(Char, 4);
    Object *obj_2 = new(Char, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_char_not_lesser_than_equal)
{
    Object *obj_1 = new(Char, 5);
    Object *obj_2 = new(Char, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_char_not_lesser_than)
{
    Object *obj_1 = new(Char, 5);
    Object *obj_2 = new(Char, 4);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = lt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_char_greater_than)
{
    Object *obj_1 = new(Char, 5);
    Object *obj_2 = new(Char, 4);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_char_not_greater_than_equal)
{
    Object *obj_1 = new(Char, 5);
    Object *obj_2 = new(Char, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}

Test(ex04, base_char_not_greater_than)
{
    Object *obj_1 = new(Char, 4);
    Object *obj_2 = new(Char, 5);
    bool result = false;

    cr_assert_not_null(obj_1);
    cr_assert_not_null(obj_2);
    result = gt(obj_1, obj_2);
    cr_assert(!result);
    delete(obj_1);
    delete(obj_2);
}