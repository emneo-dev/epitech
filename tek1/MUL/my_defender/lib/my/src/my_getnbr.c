/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_getnbr
*/

static int parse_nbr(int i, int sign, char const *str)
{
    int result = 0;

    for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++)
        result = result * 10 + (str[i] - '0');
    return (result * sign);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;
    int has_begun = 0;

    for (int i = 0; str[i] && !has_begun; i++) {
        sign = (str[i] == '-') ? sign * -1 : sign;
        has_begun = (str[i] >= '0' && str[i] <= '9') ? 1 : 0;
        result = (str[i] >= '0' && str[i] <= '9') ? parse_nbr(i, sign, str) : 0;
    }
    return (result);
}