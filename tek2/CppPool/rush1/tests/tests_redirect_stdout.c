/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush1-mathias.ressort
** File description:
** tests_redirect_stdout
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout()
{
    fflush(stderr);
    fflush(stdout);
    cr_redirect_stdout();
    cr_redirect_stderr();
}