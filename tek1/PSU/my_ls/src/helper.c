/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** helper
*/

#include "my.h"

int helper(void)
{
    my_putstr("Usage:\n");
    my_putstr("\tls [OPTION]... [FILE]...\n\n");
    my_putstr("FLAGS:\n");
    my_putstr("\t-t : Sort by time of the last modification.\n");
    my_putstr("\t-l : Display more information.\n");
    my_putstr("\t-d : Display the pointed file.\n");
    my_putstr("\t-r : Reverse the display.\n");
    my_putstr("\t-R : Display all files recursively\n");
    return (0);
}