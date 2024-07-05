/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CNAND
*/

#ifndef C_NAND_HPP_
#define C_NAND_HPP_

#include "AComponent.hpp"

namespace nts {
    class CNAND : public AComponent {
    public:
        CNAND();

        void simulate(std::size_t tick) override;

        void updatePin(std::size_t id, std::size_t tick);

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !C_NAND_HPP_ */
