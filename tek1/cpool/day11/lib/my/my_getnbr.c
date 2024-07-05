/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Some desc
*/

int print_nbr(int i, int sign, char const *str)
{
    long result = 0;

    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result *= 10;
        result = result + (str[i] - '0');
        if (result > 2147483647) {
            if (result == 2147483648 && sign == -1) {
                return (-2147483648);
            }
            return (0);
        }
        i++;
    }
    result = (sign == -1) ? -result : result;
    return (result);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int zz = 0;
    int result;
    int sign = 1;

    while (str[i] != '\0' && zz == 0) {
        if (str[i] == '-') {
            sign *= -1;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            zz = 1;
            result = print_nbr(i, sign, str);
        }
        i++;
    }
    return (result);
}
