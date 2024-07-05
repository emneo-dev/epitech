/*
** EPITECH PROJECT, 2021
** Day17
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename T>
typename T::iterator do_find(T &obj, int i)
{
    return std::find(obj.begin(), obj.end(), i);
}

#endif /* !FIND_HPP_ */
