/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** func_ptr
*/

#include <stdio.h>
#include <string.h>

#include "func_ptr_enum.h"
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i]; i++)
        printf("%c", (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i]);
    printf("\n");
}

void print_42(const char *str)
{
    (void) str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*actions[4]) (char const *str) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };
    actions[action](str);
}