/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap(Object::PAPER, "GiftPaper")
{
}

GiftPaper::GiftPaper(const std::string &title) : Wrap(Object::PAPER, title)
{
}


GiftPaper::~GiftPaper()
{
}

bool GiftPaper::wrapMeThat(Object* obj)
{
    if (!obj) {
        std::cerr << "You can't wrap nothing in paper!" << std::endl;
        return (false);
    } else if (m_content) {
        std::cerr << "Something is already in there!" << std::endl;
        return (false);
    }
    m_content = obj;
    std::cout << "tuuuut tuuut tuut" << std::endl;
    return (true);
}