/*
** EPITECH PROJECT, 2021
** Day15
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

template<typename T>
void foreach(const T (&tab)[], void (*print)(const T &a), size_t size)
{
    for (size_t i = 0; i < size; i++)
        print(tab[i]);
}

#endif /* !EX03_HPP_ */
