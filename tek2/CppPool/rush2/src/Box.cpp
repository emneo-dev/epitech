/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Box
*/

#include "Box.hpp"

Box::Box() : Wrap(Object::BOX, "Box")
{
}

Box::Box(const std::string &title) : Wrap(Object::BOX, title)
{
}

Box::~Box()
{
}

bool Box::wrapMeThat(Object* obj)
{
    if (!obj) {
        std::cerr << "You can't wrap nothing in a box!" << std::endl;
        return (false);
    } else if (m_content) {
        std::cerr << "Something is already in there!" << std::endl;
        return (false);
    } else if (!m_isOpen) {
        std::cerr << "You can't put a gift in a closed box!" << std::endl;
        return (false);
    }
    m_content = obj;
    std::cout << "tuuuut tuuut tuut" << std::endl;
    return (true);
}