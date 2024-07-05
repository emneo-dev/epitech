/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Header file for libmy
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char *concat_params(int argc, char **argv);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
int my_printf(char *str, ...);
int my_printf_su(va_list *aq);
int my_printf_i(va_list *aq);
int my_printf_perc(va_list *aq);
int my_printf_s(va_list *aq);
int my_printf_p(va_list *aq);
int my_printf_c(va_list *aq);
int my_printf_o(va_list *aq);
int my_printf_b(va_list *aq);
int my_printf_u(va_list *aq);
int my_printf_xl(va_list *aq);
int my_printf_xu(va_list *aq);
int my_printf_m(va_list *aq);

#endif /* MY_H */