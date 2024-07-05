/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CClock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "AComponent.hpp"

namespace nts {
    class CClock : public AComponent {
    public:
        CClock();

        void simulate(std::size_t tick) override;

        void updatePin(std::size_t id, std::size_t tick);

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !CLOCK_HPP_ */
