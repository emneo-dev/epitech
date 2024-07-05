/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C4069
*/

#include "Factory.hpp"
#include "C4069.hpp"

namespace nts {
    C4069::C4069()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({3, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({5, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({9, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({11, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({13, nts::Tristate::UNDEFINED, nullptr, 0, 0});

        _totalPins.push_back({2, nts::Tristate::UNDEFINED, nullptr, 0});
        _totalPins.push_back({4, nts::Tristate::UNDEFINED, nullptr, 0});
        _totalPins.push_back({6, nts::Tristate::UNDEFINED, nullptr, 0});
        _totalPins.push_back({8, nts::Tristate::UNDEFINED, nullptr, 0});
        _totalPins.push_back({10, nts::Tristate::UNDEFINED, nullptr, 0});
        _totalPins.push_back({12, nts::Tristate::UNDEFINED, nullptr, 0});

        auto _factory = nts::Factory();
        _components[0] = std::move(_factory.createComponent("CNOT"));
        _components[1] = std::move(_factory.createComponent("CNOT"));
        _components[2] = std::move(_factory.createComponent("CNOT"));
        _components[3] = std::move(_factory.createComponent("CNOT"));
        _components[4] = std::move(_factory.createComponent("CNOT"));
        _components[5] = std::move(_factory.createComponent("CNOT"));

        _components[0]->setLink(1, *this, 1);
        setLink(2, *_components[0], 2);

        _components[1]->setLink(1, *this, 3);
        setLink(4, *_components[1], 2);

        _components[2]->setLink(1, *this, 5);
        setLink(6, *_components[2], 2);

        _components[3]->setLink(1, *this, 9);
        setLink(8, *_components[3], 2);

        _components[4]->setLink(1, *this, 11);
        setLink(10, *_components[4], 2);

        _components[5]->setLink(1, *this, 13);
        setLink(12, *_components[5], 2);
    }

    void C4069::simulate(std::size_t tick) {
        updatePin(2, tick);
        updatePin(4, tick);
        updatePin(6, tick);
        updatePin(8, tick);
        updatePin(10, tick);
        updatePin(12, tick);
    }

    void C4069::dump() const {
        for (const auto & totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
        std::cout << "pin " << std::setw(2) << getPin(1).id << " : " << std::setw(10) << print(getPin(1).state)
                  << " -> pin " << std::setw(2) << getPin(2).id << " : " << print(getPin(2).state) << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(3).id << " : " << std::setw(10) << print(getPin(3).state)
                  << " -> pin " << std::setw(2) << getPin(4).id << " : " << print(getPin(4).state) << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(5).id << " : " << std::setw(10) << print(getPin(5).state)
                  << " -> pin " << std::setw(2) << getPin(6).id << " : " << print(getPin(6).state) << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(9).id << " : " << std::setw(10) << print(getPin(9).state)
                  << " -> pin " << std::setw(2) << getPin(8).id << " : " << print(getPin(8).state) << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(11).id << " : " << std::setw(10) << print(getPin(11).state)
                  << " -> pin " << std::setw(2) << getPin(10).id << " : " << print(getPin(10).state) << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(13).id << " : " << std::setw(10) << print(getPin(13).state)
                  << " -> pin " << std::setw(2) << getPin(12).id << " : " << print(getPin(12).state) << std::endl;
    }
}