//
// Created by huntears on 03/03/2021.
//

#include <algorithm>

#include "Circuit.hpp"
#include "Errors.hpp"
#include "Utilities.hpp"
#include "Factory.hpp"

namespace nts
{
    Circuit::Circuit() :
        _currentTick(0){
        auto factory = nts::Factory();
        _powerOff = std::move(factory.createComponent("CFalse"));
        _powerOn = std::move(factory.createComponent("CTrue"));
        _powerUndefined = std::move(factory.createComponent("CUndefined"));
    };

    [[noreturn]] void Circuit::loop() {
        while (true) {
            simulate();
            display();
        }
    }

    void Circuit::display() const {
        std::vector<std::pair<std::string, nts::Tristate>> _sortedInputs;
        std::vector<std::pair<std::string, nts::Tristate>> _sortedOutputs;

        // TODO: Check if this is even remotely accurate
        auto sortFunc = [](const std::pair<std::string, nts::Tristate>& a, const std::pair<std::string, nts::Tristate>& b) {
            return a.first < b.first;
        };

        for (auto i = std::next(_inputs.begin()); i != _inputs.end(); ++i)
            _sortedInputs.emplace_back(i->first, i->second->getPinState(1));
        for (auto i = std::next(_outputs.begin()); i != _outputs.end(); ++i)
            _sortedOutputs.emplace_back(i->first, i->second->getPinState(1));

        std::sort(_sortedInputs.begin(), _sortedInputs.end(), sortFunc);
        std::sort(_sortedOutputs.begin(), _sortedOutputs.end(), sortFunc);

        // TODO: Display all inputs and outputs in alphabetical order
        std::cout << "tick: " << this->_currentTick << std::endl
            << "input(s):" << std::endl;
        for (const std::pair<std::string, nts::Tristate>& input : _sortedInputs)
            std::cout << "  " << input.first << ": " << getStringFromTristate(input.second) << std::endl;
        std::cout << "output(s):" << std::endl;
        for (const std::pair<std::string, nts::Tristate>& output : _sortedOutputs)
            std::cout << "  " << output.first << ": " << getStringFromTristate(output.second) << std::endl;
    }

    void Circuit::addComponent(const std::string &name, std::unique_ptr<nts::IComponent> component) {
        if (_components.count(name) != 0 || _inputs.count(name) != 0 || _outputs.count(name) != 0)
            throw AlreadyExistingName();
        _components.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>(name, std::move(component)));
    }

    void Circuit::addInput(const std::string &name, std::unique_ptr<nts::IComponent> component) {
        if (_components.count(name) != 0 || _inputs.count(name) != 0 || _outputs.count(name) != 0)
            throw AlreadyExistingName();
        _inputs.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>(name, std::move(component)));
    }

    void Circuit::addOutput(const std::string &name, std::unique_ptr<nts::IComponent> component) {
        if (_components.count(name) != 0 || _inputs.count(name) != 0 || _outputs.count(name) != 0)
            throw AlreadyExistingName();
        _outputs.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>(name, std::move(component)));
    }

    // Keeping that for later if need be :
    // if (!c.empty())
    //     std::cout << *c.front();
    void Circuit::dump() const {
        for (auto i = std::next(_components.begin()); i != _components.end(); ++i)
            i->second->dump();
        for (auto i = std::next(_inputs.begin()); i != _inputs.end(); ++i)
            i->second->dump();
        for (auto i = std::next(_outputs.begin()); i != _outputs.end(); ++i)
            i->second->dump();
    }

    void Circuit::setInputValue(const std::string &inputName, nts::Tristate state) {
        if (_inputs.count(inputName) == 0)
            throw ComponentNameUnknown();
        switch (state) {
            case nts::Tristate::FALSE:
                _inputs[inputName]->setLink(0, *this->_powerOff, 0);
                break;
            case nts::Tristate::TRUE:
                _inputs[inputName]->setLink(0, *this->_powerOn, 0);
                break;
            case nts::Tristate::UNDEFINED:
                _inputs[inputName]->setLink(0, *this->_powerUndefined, 0);
                break;
        }
    }

    void Circuit::simulate() {
        for (auto i = std::next(_outputs.begin()); i != _outputs.end(); ++i)
            i->second->simulate(_currentTick);
    }
}