/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** printf clone
*/

#include <my.h>
#include <stdarg.h>
#include <unistd.h>

static int error_handling(va_list *va)
{
    va = va;
    return (0);
}

static int (*get_function(char flag))(va_list *) {

    char *flag_list = "Sdi%spcobuxXm";
    int (*arr[13])(va_list *) = {my_printf_su, my_printf_i, my_printf_i,
        my_printf_perc, my_printf_s, my_printf_p, my_printf_c, my_printf_o,
        my_printf_b, my_printf_u, my_printf_xl, my_printf_xu, my_printf_m};

    for (int i = 0; i < my_strlen(flag_list); i++)
        if (flag_list[i] == flag)
            return arr[i];
    return error_handling;
}

static int handle_flags(char flag, va_list *aq)
{
    int (*fp)(va_list *) = get_function(flag);
    return (fp(aq));
}

int my_printf(char *str, ...)
{
    int ret = 0;
    va_list aq;

    va_start(aq, str);
    for (int i = 0; str[i]; i++, ret++) {
        if (str[i] == '%') {
            ret += handle_flags(str[i + 1], &aq) - 1;
            i++;
        }
        else
            write(1, str + i, 1);
    }
    return (ret);
}
