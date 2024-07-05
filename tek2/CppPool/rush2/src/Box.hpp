/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP

#include "Wrap.hpp"

class Box : public Wrap
{
    public:
        Box(const std::string &title);
        Box();
        virtual ~Box();
        virtual bool wrapMeThat(Object* obj);

    protected:
    private:
};

#endif /* !BOX_HPP_ */