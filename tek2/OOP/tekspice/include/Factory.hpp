/*
** EPITECH PROJECT, 2021
** nano
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IComponent.hpp"
#include <memory>
#include <unordered_map>

namespace nts
{

    class Factory {
    private:
        const std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (Factory::*)() const> _functionCallMap = {
                {"CFalse", &Factory::createFalse},
                {"CTrue", &Factory::createTrue},
                {"CUndefined", &Factory::createUndefined},
                {"CInput", &Factory::createInput},
                {"COutput", &Factory::createOutput},
                {"CClock", &Factory::createClock},
                {"CXOR", &Factory::createXOR},
                {"COR", &Factory::createOR},
                {"CNOR", &Factory::createNOR},
                {"CNAND", &Factory::createNAND},
                {"CAND", &Factory::createAND},
                {"C4081", &Factory::create4081},
                {"C4071", &Factory::create4071},
                {"C4069", &Factory::create4069},
                {"C4030", &Factory::create4030},
                {"C4011", &Factory::create4011},
                {"C4001", &Factory::create4001},
                {"CNOT", &Factory::createNOT}
        };

        std::unique_ptr<nts::IComponent> createTrue() const noexcept;
        std::unique_ptr<nts::IComponent> createFalse() const noexcept;
        std::unique_ptr<nts::IComponent> createUndefined() const noexcept;
        std::unique_ptr<nts::IComponent> createInput() const noexcept;
        std::unique_ptr<nts::IComponent> createOutput() const noexcept;
        std::unique_ptr<nts::IComponent> createClock() const noexcept;
        std::unique_ptr<nts::IComponent> createXOR() const noexcept;
        std::unique_ptr<nts::IComponent> createOR() const noexcept;
        std::unique_ptr<nts::IComponent> createNOR() const noexcept;
        std::unique_ptr<nts::IComponent> createNAND() const noexcept;
        std::unique_ptr<nts::IComponent> createAND() const noexcept;
        std::unique_ptr<nts::IComponent> create4081() const noexcept;
        std::unique_ptr<nts::IComponent> create4071() const noexcept;
        std::unique_ptr<nts::IComponent> create4069() const noexcept;
        std::unique_ptr<nts::IComponent> create4030() const noexcept;
        std::unique_ptr<nts::IComponent> create4011() const noexcept;
        std::unique_ptr<nts::IComponent> create4001() const noexcept;
        std::unique_ptr<nts::IComponent> createNOT() const noexcept;

    public:
        std::unique_ptr<nts::IComponent> createComponent(const std::string &name) const;
    };
}

#endif /* !FACTORY_HPP_ */
