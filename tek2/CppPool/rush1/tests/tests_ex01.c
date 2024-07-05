/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush1-mathias.ressort
** File description:
** tests_ex01
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>

#include "new.h"
#include "player.h"

void redirect_all_stdout();

TestSuite(ex01, .timeout=1);

Test(ex01, base_example, .init=redirect_all_stdout)
{
    Object *player = new(Player);

    cr_assert_not_null(player);
    delete(player);
    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n~Player()\n", "");
}

Test(ex01, base_example_null_va_new, .init=redirect_all_stdout)
{
    Object *player = va_new(Player, NULL);

    cr_assert_not_null(player);
    delete(player);
    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n~Player()\n", "");
}

Test(ex01, base_example_too_many_new_arguments, .init=redirect_all_stdout)
{
    Object *player = new(Player, 42, "rofl", "This is not fun",
        "Please help me");

    cr_assert_not_null(player);
    delete(player);
    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n~Player()\n", "");
}

Test(ex01, null_new, .signal=SIGABRT)
{
    new(NULL);
}

Test(ex01, weird_new, .signal=SIGSEGV)
{
    new((void *)1);
}

Test(ex01, null_delete, .signal=SIGABRT)
{
    delete(NULL);
}

Test(ex01, weird_delete, .signal=SIGSEGV)
{
    delete((void *)1);
}

// Disabled as it is finally impossible to test
Test(ex01, double_delete, .signal=16, .disabled=true)
{
    Object *player = new(Player);

    cr_assert_not_null(player);
    delete(player);
    delete(player);
}