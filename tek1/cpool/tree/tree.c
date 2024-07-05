/*
** EPITECH PROJECT, 2019
** firtree
** File description:
** Main file for the firtree project
*/

int my_putchar(char character);

int compute_base(int size_tree);

int display_layer(int, int);

int display_trunk(int, int);

int predisplay_leaves(int, int);

int tree(int size)
{
    int base_size = compute_base(size);
    predisplay_leaves(base_size, size);
    display_trunk(size, base_size);
    return (0);
}

int predisplay_leaves(int base_size, int n)
{
    int size = 1;
    int y = 2;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            y += 2;
        size -= y;
        for (int z = 1; z <= i + 3; z++) {
            size += 2;
            int spaces = (base_size - 1) / 2 + 1 - ((size - 1) / 2 + 1);
            display_layer(spaces - 1, size);
        }
    }
    return (0);
}

int display_layer(int nb_space, int nb_leaves)
{
    for (int i = 0; i <= nb_space; i++) {
        my_putchar(' ');
    }
    for (int i = 0; i < nb_leaves; i++) {
        my_putchar('*');
    }
    my_putchar('\n');
    return (0);
}

int compute_base(int n)
{
    int size = 1;
    int y = 2;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            y += 2;
        size -= y;
        for (int z = 1; z <= i + 3; z++) {
            size += 2;
        }
    }
    return (size);
}

int display_trunk(int size, int base_size)
{
    if (size % 2 == 0)
        size++;
    for (int i = 1; i <= size; i++) {
        int spaces = (base_size -1) / 2 + 1 - ((size - 1) / 2 + 1);
        for (int z = 0; z <= spaces - 1; z++) {
            my_putchar(' ');
        }
        for (int z = 0; z < size; z++) {
            my_putchar('|');
        }
        my_putchar('\n');
    }
    return (0);
}
