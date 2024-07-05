/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** COR
*/

#ifndef C_OR_HPP_
#define C_OR_HPP_

#include "AComponent.hpp"

namespace nts {
    class COR : public AComponent {
    public:
        COR();

        void simulate(std::size_t tick) override;

        void updatePin(std::size_t id, std::size_t tick);

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !C_OR_HPP_ */
