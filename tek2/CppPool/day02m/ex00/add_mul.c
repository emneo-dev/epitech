/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** add_mul
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int product = *second * *first;
    *first = *first + *second;
    *second = product;
}