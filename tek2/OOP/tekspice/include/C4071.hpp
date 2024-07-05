/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include <array>

#include "AComponent.hpp"

namespace nts {
    class C4071 : public AComponent {
    public:
        C4071();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
        std::array<std::unique_ptr<nts::IComponent>, 4> _components;
    };
}

#endif /* !C4071_HPP_ */
