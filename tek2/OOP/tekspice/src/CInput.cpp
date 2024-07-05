/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CInput
*/

#include "CInput.hpp"

namespace nts {
    CInput::CInput()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::UNDEFINED, nullptr, 0, 0});
    }

    void CInput::simulate(std::size_t tick) {
        updatePin(1, tick);
    }

    void CInput::dump() const {
        for (const auto & totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
    }
}