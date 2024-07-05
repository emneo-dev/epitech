/*
** EPITECH PROJECT, 2021
** LittlePoney
** File description:
** LittlePoney
*/

#include "LittlePoney.hpp"

LittlePoney::LittlePoney(const std::string &title) : Toy(title)
{
}

LittlePoney::~LittlePoney()
{
}

Object *LittlePoney::isTaken()
{
    if (m_taken) {
        std::cerr << m_title << " is already taken by someone!" << std::endl;
        return (nullptr);
    }
    std::cout << "yo man" << std::endl;
    m_taken = true;
    return (this);
}

std::string LittlePoney::getToyType() const
{
    return "LittlePoney";
}