/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CFalse
*/

#include "CFalse.hpp"

namespace nts {
    CFalse::CFalse()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::FALSE, nullptr, 0, 0});
    }

    void CFalse::simulate(std::size_t tick) {
    }

    void CFalse::dump() const {
        for (const auto & totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
    }

    void CFalse::updatePin(std::size_t id, std::size_t tick) {
        // Yes there's stuff here
    }
}