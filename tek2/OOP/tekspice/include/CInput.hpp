/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CInput
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class CInput : public AComponent {
    public:
        CInput();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !INPUT_HPP_ */
