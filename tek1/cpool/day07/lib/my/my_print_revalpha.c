/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** Some desc
*/

int my_putchar(char);

int my_print_revalpha(void)
{
    char i;

    for (i = 'z'; i >= 'a'; --i) {
        my_putchar(i);
    }
    return (0);
}
