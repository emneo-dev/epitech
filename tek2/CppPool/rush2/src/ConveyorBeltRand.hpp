/*
** EPITECH PROJECT, 2021
** ConveyorBeltRand
** File description:
** ConveyorBeltRand
*/

#ifndef CONVEYORBELTRAND_HPP_
#define CONVEYORBELTRAND_HPP_

#include "Object.hpp"
#include "PapaXmasConveyorBelt.hpp"

class ConveyorBeltRand : public PapaXmasConveyorBelt
{
public:
    ConveyorBeltRand();
    ~ConveyorBeltRand();

    void serialization();
    void IN();

protected:
private:
};

#endif /* !CONVEYORBELTRAND_HPP_ */