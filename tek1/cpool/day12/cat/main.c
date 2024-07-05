/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** Main file for the cat replica
*/

void cat(char const *file_path);

void no_arg_cat(void);

int main(int argc, char const *argv[])
{
    if (argc < 2)
        no_arg_cat();
    for (int i = 0; i < argc - 1; i++)
        cat(argv[i + 1]);
    return (0);
}