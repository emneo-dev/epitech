/*
** EPITECH PROJECT, 2021
** Toy
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Object.hpp"

class Toy : public Object{
    public:
        Toy(const std::string &title);
        virtual ~Toy() {};
        virtual std::string getToyType() const = 0;
    protected:
    private:
};

#endif /* !TOY_HPP_ */