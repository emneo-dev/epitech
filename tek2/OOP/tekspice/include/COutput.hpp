/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** COutput
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class COutput : public AComponent {
    public:
        COutput();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !OUTPUT_HPP_ */
