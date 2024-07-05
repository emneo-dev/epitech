//
// Created by hunte on 3/6/2021.
//

#ifndef NANOTEKSPICE_CUNDEFINED_HPP
#define NANOTEKSPICE_CUNDEFINED_HPP

#include "AComponent.hpp"

namespace nts {
    class CUndefined : public AComponent {
    public:
        CUndefined();

        void simulate(std::size_t tick) override;

        void dump() const override;

    protected:
    private:
    };
}

#endif //NANOTEKSPICE_CUNDEFINED_HPP
