/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include <array>

#include "AComponent.hpp"

namespace nts
{
    class C4008 : public AComponent
    {
    public:
        C4008();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
        std::array<std::unique_ptr<nts::IComponent>, 52> _components;
    };
}

#endif /* !C4008_HPP_ */