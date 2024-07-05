/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CXOR
*/

#ifndef C_XOR_HPP_
#define C_XOR_HPP_
#include "AComponent.hpp"

namespace nts {
    class CXOR : public AComponent {
    public:
        CXOR();

        void simulate(std::size_t tick) override;

        void updatePin(std::size_t id, std::size_t tick);

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !C_XOR_HPP_ */
