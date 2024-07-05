//
// Created by hunte on 3/7/2021.
//

#include "CNOT.hpp"

namespace nts {
    CNOT::CNOT()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::UNDEFINED, nullptr, 0, 0});

        _totalPins.push_back({2, nts::Tristate::UNDEFINED, nullptr, 0});
    }

    void CNOT::simulate(std::size_t tick) {
        AComponent::updatePin(1, tick);
        if (getPin(1).state == nts::Tristate::TRUE)
            assignPin(2, nts::Tristate::FALSE, tick);
        else if (getPin(1).state == nts::Tristate::FALSE)
            assignPin(2, nts::Tristate::TRUE, tick);
        else
            assignPin(2, nts::Tristate::UNDEFINED, tick);
    }

    void CNOT::updatePin(std::size_t id, std::size_t tick) {
        simulate(tick);
    }

    void CNOT::dump() const {
        for (auto &totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
    }
}