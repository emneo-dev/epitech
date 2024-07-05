/*
** EPITECH PROJECT, 2019
** rush1-1
** File description:
** Display a square
*/

int center(int width);

int base(int width);

void rush(int a, int b)
{
    if (a <= 0 || b <= 0) {
        write(2, "Invalid size\n", 13);
        return (1);
    }
    for (int i = 1; i <= b; i++) {
        if (i == 1 || i == b) {
            base(a);
            my_putchar('\n');
        }
        else {
            center(a);
            my_putchar('\n');
        }
    }
    return (0);
}