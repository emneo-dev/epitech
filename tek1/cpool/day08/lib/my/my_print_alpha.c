/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** Some desc
*/

int my_putchar(char);

int my_print_alpha(void)
{
    char i;

    for (i = 'a'; i <= 'z'; ++i) {
        my_putchar(i);
    }
    return (0);
}
