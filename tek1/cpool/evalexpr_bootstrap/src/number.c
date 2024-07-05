/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** Converts a given sting as an integer
*/

int number(char **str)
{
    int result = 0;
    int sign = 1;

    while (!(**str <= '9' && **str >= '0' || **str == '-'))
        (*str)++;
    for (int i = 0; **str == '-'; (*str)++)
        sign = -sign;
    for (int i = 0; **str <= '9' && **str >= '0'; (*str)++, result *= 10)
        result += **str - '0';
    result /= 10 * sign;
    return (result);
}
