/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexC_ANDre.flion
** File description:
** CAND
*/

#ifndef C_AND_HPP_
#define C_AND_HPP_

#include "AComponent.hpp"

namespace nts {
    class CAND : public AComponent {
    public:
        CAND();

        void simulate(std::size_t tick) override;

        void updatePin(std::size_t id, std::size_t tick);

        void dump() const override;

    protected:
    private:
    };
}

#endif /* !C_AND_HPP_ */
