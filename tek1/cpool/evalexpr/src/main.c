/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** Main file for the evalexpr project bootstrap
*/

#include <my.h>

int main(int ac, char **av)
{
    /*if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }*/
    eval_expr("4+(3+4)*5");
    return (84);
}
