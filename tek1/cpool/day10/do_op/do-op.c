/*
** EPITECH PROJECT, 2019
** do_op
** File description:
** Do an operation between two numbers
*/

#include <my.h>

static int do_operation(int const a, int const b, char const *op);

static int do_division(int const a, int const b);

static int do_modulo(int const a, int const b);

static int do_addition(int const a, int const b);

int do_multiply(int const a, int const b);

int do_substract(int const a, int const b);

static char get_operator(char *str);

int main(int argc, char const *argv[])
{
    if (argc != 4)
        return (84);
    int return_value =  (do_operation(my_getnbr(argv[1]), my_getnbr(argv[3]), argv[2]));
    my_putchar('\n');
    return (return_value);
}

static int do_operation(int const a, int const b, char const *op)
{
    switch (op[0]) {
        case '-' :
            return (do_substract(a, b));
        case '+' :
            return (do_addition(a, b));
        case '*' :
            return (do_multiply(a, b));
        case '/' :
            return (do_division(a, b));
        case '%' :
            return (do_modulo(a, b));
        default :
            my_put_nbr(0);
            return (84);
    }
}

static int do_division(int const a, int const b)
{
    if (b == 0) {
        my_putstr("Stop: division by zero");
        return (84);
    }
    my_put_nbr((long)(a / b));
    return (0);
}

static int do_modulo(int const a, int const b)
{
    if (b == 0) {
        my_putstr("Stop: modulo by zero");
        return (84);
    }
    my_put_nbr((long)(a % b));
    return (0);
}

static int do_addition(int const a, int const b)
{
    if (a > 2147483647 - b)
        return (84);
    my_put_nbr((long)(a + b));
    return (0);
}
