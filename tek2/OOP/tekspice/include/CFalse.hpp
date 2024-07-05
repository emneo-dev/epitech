/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CFalse
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "AComponent.hpp"

namespace nts {
    class CFalse : public AComponent {
    public:
        CFalse();

        void simulate(std::size_t tick) override;

        void dump() const override;

        void updatePin(std::size_t id, std::size_t tick) override;

    protected:
    private:
    };
}

#endif /* !FALSE_HPP_ */
