//
// Created by hunte on 3/6/2021.
//

#include "CUndefined.hpp"

namespace nts {
    CUndefined::CUndefined()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::FALSE, nullptr, 0, 0});
    }

    void CUndefined::simulate(std::size_t tick) {
    }

    void CUndefined::dump() const {
        for (const auto & totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
    }
}