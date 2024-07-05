/*
** EPITECH PROJECT, 2021
** Day15
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <string>

template<typename T>
int compare(const T &a, const T &b)
{
    return a == 0 ? 0 : (a < b ? -1 : 1);
}

int compare(char const *a, char const *b)
{
    return a == 0 ? 0 : (a < b ? -1 : 1);
}

#endif /* !EX01_HPP_ */
