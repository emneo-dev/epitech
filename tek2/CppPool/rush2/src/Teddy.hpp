/*
** EPITECH PROJECT, 2021
** Teddy
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include "Toy.hpp"

class Teddy : public Toy
{
public:
    Teddy(const std::string &title);
    virtual ~Teddy();
    virtual Object *isTaken();
    std::string getToyType() const;
protected:
private:
};

#endif /* !TEDDY_HPP_ */