//
// Created by hunte on 3/7/2021.
//

#ifndef NANOTEKSPICE_CNOT_HPP
#define NANOTEKSPICE_CNOT_HPP

#include "AComponent.hpp"

namespace nts {
    class CNOT : public AComponent {
    public:
        CNOT();

        void simulate(std::size_t tick) override;

        void updatePin(std::size_t id, std::size_t tick);

        void dump() const override;

    protected:
    private:
    };
}

#endif //NANOTEKSPICE_CNOT_HPP
