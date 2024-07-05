/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** LittlePoney
*/

#ifndef LITTLEPONEY_HPP_
#define LITTLEPONEY_HPP_

#include "Toy.hpp"

class LittlePoney : public Toy
{
    public:
        LittlePoney(const std::string &title);
        ~LittlePoney();

        virtual Object *isTaken();
        std::string getToyType() const;
    protected:
    private:
};

#endif /* !LITTLEPONEY_HPP_ */