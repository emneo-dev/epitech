/*
** EPITECH PROJECT, 2021
** Day15
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>
#include <cstddef>

template<typename T>
T min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    return a < b ? a : b;
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    return a < b ? a : b;
}

template<typename T>
T templateMin(const T (&arr)[], size_t size)
{
    T mine = arr[0];
    for (size_t i = 0; i < size; i++)
        mine = min<T>(mine, arr[i]);
    return mine;
}

int nonTemplateMin(const int (&arr)[], size_t size)
{
    int mine = arr[0];
    for (size_t i = 0; i < size; i++)
        mine = min(mine, arr[i]);
    return mine;
}

#endif /* !EX02_HPP_ */
