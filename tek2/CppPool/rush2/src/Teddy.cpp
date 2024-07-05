/*
** EPITECH PROJECT, 2021
** Teddy.cpp
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &title) : Toy(title)
{
}

Teddy::~Teddy()
{
}

Object *Teddy::isTaken()
{
    if (m_taken) {
        std::cerr << m_title << " is already taken by someone!" << std::endl;
        return (nullptr);
    }
    std::cout << "gra hu" << std::endl;
    m_taken = true;
    return (this);
}

std::string Teddy::getToyType() const
{
    return "Teddy";
}