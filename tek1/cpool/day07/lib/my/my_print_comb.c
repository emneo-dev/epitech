/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** Some desc
*/

int my_putchar(char);

int my_print_comb(void)
{
    char a;
    char b;
    char c;

    for (a = '0'; a <= '7'; a++) {
        for (b = a + 1; b <= '8'; b++) {
            for (c = b + 1; c <= '9'; c++) {
                my_putchar(a);
                my_putchar(b);
                my_putchar(c);
                if (a == '7' && b == '8' && c == '9') {
                    return (0);
                }
                else {
                    my_putchar(',');
                    my_putchar(' ');
                }
            }
        }
    }
}
