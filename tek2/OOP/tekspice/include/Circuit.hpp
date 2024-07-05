//
// Created by huntears on 03/03/2021.
//

#ifndef NANO_CIRCUIT_HPP
#define NANO_CIRCUIT_HPP

#include <unordered_map>
#include <memory>

#include "IComponent.hpp"

namespace nts {
    class Circuit {
    private:
        std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _inputs;
        std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _outputs;
        std::unique_ptr<nts::IComponent> _powerOn;
        std::unique_ptr<nts::IComponent> _powerOff;
        std::unique_ptr<nts::IComponent> _powerUndefined;

        std::size_t _currentTick;
    public:
        Circuit();

        void addComponent(const std::string &name, std::unique_ptr<nts::IComponent> component);
        void addInput(const std::string &name, std::unique_ptr<nts::IComponent> component);
        void addOutput(const std::string &name, std::unique_ptr<nts::IComponent> component);
        void dump() const;
        void display() const;
        void setInputValue(const std::string &inputName, nts::Tristate state);
        void simulate();

        [[noreturn]] void loop();
    };
}

#endif //NANO_CIRCUIT_HPP
