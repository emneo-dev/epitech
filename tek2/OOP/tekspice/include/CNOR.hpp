/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CNOR
*/

#ifndef C_NOR_HPP_
#define C_NOR_HPP_

#include "AComponent.hpp"

namespace nts {
    class CNOR : public AComponent {
    public:
        CNOR();

        void simulate(std::size_t tick) override;

        void updatePin(std::size_t id, std::size_t tick);

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !C_NOR_HPP_ */
