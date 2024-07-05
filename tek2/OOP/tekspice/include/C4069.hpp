/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include <array>

#include "AComponent.hpp"

namespace nts {
    class C4069 : public AComponent {
    public:
        C4069();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
        std::array<std::unique_ptr<nts::IComponent>, 6> _components;
    };
}

#endif /* !C4069_HPP_ */
