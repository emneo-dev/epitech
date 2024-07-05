/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** CTrue
*/

#include "CTrue.hpp"

namespace nts {
    CTrue::CTrue()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::TRUE, nullptr, 0, 0});
    }

    void CTrue::simulate(std::size_t tick){}

    void CTrue::dump() const {
        for (auto &totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
    }

    void CTrue::updatePin(std::size_t id, std::size_t tick) {
        // Yes there's stuff here
    }
}