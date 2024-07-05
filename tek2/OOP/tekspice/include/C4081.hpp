/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include <array>

#include "AComponent.hpp"

namespace nts {
    class C4081 : public AComponent {
    public:
        C4081();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
        std::array<std::unique_ptr<nts::IComponent>, 4> _components;
    };
}

#endif /* !C4081_HPP_ */
