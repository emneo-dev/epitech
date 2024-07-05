/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** Some desc
*/

int my_putchar(char);

int my_print_digits(void)
{
    char i;

    for (i = '0'; i <= '9'; ++i) {
        my_putchar(i);
    }
    return (0);
}
