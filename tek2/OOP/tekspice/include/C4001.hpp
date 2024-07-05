/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include <array>

#include "AComponent.hpp"

namespace nts {
    class C4001 : public AComponent {
    public:
        C4001();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
        std::array<std::unique_ptr<nts::IComponent>, 4> _components;
    };
}

#endif /* !C4001_HPP_ */
