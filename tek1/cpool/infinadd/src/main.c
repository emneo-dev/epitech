/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Entry file for the infinadd project
*/

#include <infinadd.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
        return (0);
    char **str = malloc(sizeof(char*) * 2);
    str = parse_args(argv[1], argv[2]);
    str = sort_nbr_str(str);
    if (is_negative(str[0]) == 0 && is_negative(str[1]) == 0)
        add_positives(str[0], str[1]);
    else if (is_negative(str[0]) && is_negative(str[1]))
        add_negatives(str[0], str[1]);
    return (0);
}
