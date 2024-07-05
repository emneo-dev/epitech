/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** C4030
*/

#include "Factory.hpp"
#include "C4030.hpp"

namespace nts {
    C4030::C4030()
            : AComponent() {
        _totalPins.push_back({1, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({2, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({5, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({6, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({8, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({9, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({12, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({13, nts::Tristate::UNDEFINED, nullptr, 0, 0});

        _totalPins.push_back({3, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({4, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({10, nts::Tristate::UNDEFINED, nullptr, 0, 0});
        _totalPins.push_back({11, nts::Tristate::UNDEFINED, nullptr, 0, 0});

        auto _factory = nts::Factory();
        _components[0] = std::move(_factory.createComponent("CXOR"));
        _components[1] = std::move(_factory.createComponent("CXOR"));
        _components[2] = std::move(_factory.createComponent("CXOR"));
        _components[3] = std::move(_factory.createComponent("CXOR"));

        _components[0]->setLink(1, *this, 1);
        _components[0]->setLink(2, *this, 2);
        setLink(3, *_components[0], 3);

        _components[1]->setLink(1, *this, 5);
        _components[1]->setLink(2, *this, 6);
        setLink(4, *_components[1], 3);

        _components[2]->setLink(1, *this, 8);
        _components[2]->setLink(2, *this, 9);
        setLink(10, *_components[2], 3);

        _components[3]->setLink(1, *this, 12);
        _components[3]->setLink(2, *this, 13);
        setLink(11, *_components[3], 3);
    }

    void C4030::simulate(std::size_t tick) {
        updatePin(3, tick);
        updatePin(4, tick);
        updatePin(10, tick);
        updatePin(11, tick);
    }

    void C4030::dump() const {
        for (const auto & totalPin : _totalPins) {
            std::cout << "pin " << std::setw(2) << totalPin.id << " linked : ";
            if (getPin(totalPin.id).linkedComponent == nullptr)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
        std::cout << "pin " << std::setw(2) << getPin(1).id << " : " << std::setw(10) << print(getPin(1).state)
                  << " XOR pin " << std::setw(2) << getPin(2).id << " : " << std::setw(10) << print(getPin(2).state);
        std::cout << " -> pin " << std::setw(2) << getPin(3).id << " : " << std::setw(10) << print(getPin(3).state)
                  << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(5).id << " : " << std::setw(10) << print(getPin(5).state)
                  << " XOR pin " << std::setw(2) << getPin(6).id << " : " << std::setw(10) << print(getPin(6).state);
        std::cout << " -> pin " << std::setw(2) << getPin(4).id << " : " << std::setw(10) << print(getPin(4).state)
                  << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(8).id << " : " << std::setw(10) << print(getPin(8).state)
                  << " XOR pin " << std::setw(2) << getPin(9).id << " : " << std::setw(10) << print(getPin(9).state);
        std::cout << " -> pin " << std::setw(2) << getPin(10).id << " : " << std::setw(10) << print(getPin(10).state)
                  << std::endl;
        std::cout << "pin " << std::setw(2) << getPin(12).id << " : " << std::setw(10) << print(getPin(12).state)
                  << " XOR pin " << std::setw(2) << getPin(13).id << " : " << std::setw(10) << print(getPin(13).state);
        std::cout << " -> pin " << std::setw(2) << getPin(11).id << " : " << std::setw(10) << print(getPin(11).state)
                  << std::endl;
    }
}