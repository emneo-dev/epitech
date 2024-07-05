/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CClock
*/

#include "CClock.hpp"

namespace nts {
    CClock::CClock()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::UNDEFINED, nullptr, 0, 0});
    }

    // TODO
    void CClock::simulate(std::size_t tick) {
        for (size_t i = 0; i < tick; i++)
            assignPin(1, nts::Tristate::UNDEFINED, tick);
    }

    void CClock::updatePin(std::size_t id, std::size_t tick) {
        simulate(tick);
    }

    void CClock::dump() const {
        for (const auto & totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
    }
}