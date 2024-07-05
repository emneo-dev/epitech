/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** IConvoyerBelt
*/

#ifndef ICONVOYERBELT_HPP_
#define ICONVOYERBELT_HPP_

#include "Object.hpp"

class IConveyorBelt {
public:
    virtual ~IConveyorBelt() {}
    virtual Object *Take() = 0;
    virtual bool Put(Object*) = 0;
    virtual void IN() = 0;
    virtual void OUT() = 0;
    virtual std::string Look() const = 0;
protected:
private:
};

#endif /* !ICONVOYERBELT_HPP_ */
