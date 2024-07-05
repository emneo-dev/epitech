/*
** EPITECH PROJECT, 2021
** nano
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <vector>
#include <iostream>

namespace nts
{

    #pragma warning( disable : 4804 )

    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent;

    typedef struct pin_s
    {
        std::size_t id;
        nts::Tristate state;
        nts::IComponent *linkedComponent;
        std::size_t linkedPin;
        std::size_t lastTickSimulated;
    } pin_t;

    class IComponent
    {
    public:
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate getPinState(std::size_t pin) const = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual const std::vector<nts::pin_t> &getPins() const = 0;
        virtual const nts::pin_t &getPin(std::size_t id) const = 0;
        //virtual const nts::Tristate updateAndGetPinState(std::size_t pin)
        virtual void dump() const = 0;
        virtual void updatePin(std::size_t id, std::size_t tick) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
