/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CTrue
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "AComponent.hpp"

namespace nts {
    class CTrue : public AComponent {
    public:
        CTrue();

        void simulate(std::size_t tick) override;

        void dump() const override;

        void updatePin(std::size_t id, std::size_t tick) override;

    protected:
    private:
    };
}

#endif /* !TRUE_HPP_ */
