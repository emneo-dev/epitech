/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
** Some desc
*/

int my_putchar(char);

static void print_int(int i)
{
    my_putchar('0' + ((i - (i % 10)) / 10));
    my_putchar('0' + (i % 10));
}

int my_print_comb2(void)
{
    int a;
    int b;

    for (a = 0; a <= 98; a++) {
        for (b = a + 1; b <= 99; b++) {
            print_int(a);
            my_putchar(' ');
            print_int(b);
            if (a == 98 && b == 99) {
                return (0);
            }
            else {
                my_putchar(',');
                my_putchar(' ');
            }
        }
    }
}
