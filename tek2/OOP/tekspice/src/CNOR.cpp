/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CNOR
*/

#include "CNOR.hpp"

namespace nts {
    CNOR::CNOR()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({2, nts::Tristate::UNDEFINED, nullptr, 0, 0});

        _totalPins.push_back({3, nts::Tristate::UNDEFINED, nullptr, 0, 0});
    }

    void CNOR::simulate(std::size_t tick) {
        AComponent::updatePin(1, tick);
        AComponent::updatePin(2, tick);
        if (getPin(1).state == nts::Tristate::TRUE || getPin(2).state == nts::Tristate::TRUE)
            assignPin(3, nts::Tristate::FALSE, tick);
        else if (getPin(1).state == nts::Tristate::FALSE && getPin(2).state == nts::Tristate::FALSE)
            assignPin(3, nts::Tristate::TRUE, tick);
        else
            assignPin(3, nts::Tristate::UNDEFINED, tick);
    }

    void CNOR::updatePin(std::size_t id, std::size_t tick) {
        simulate(tick);
    }

    void CNOR::dump() const {
        for (const auto & totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
        std::cout << "pin " << std::setw(2) << getPin(1).id << " : " << std::setw(10) << print(getPin(1).state)
                  << " NOR  pin " << std::setw(2) << getPin(2).id << " : " << std::setw(10) << print(getPin(2).state);
        std::cout << "-> pin " << std::setw(2) << getPin(3).id << " : " << std::setw(10) << print(getPin(3).state)
                  << std::endl;
    }
}