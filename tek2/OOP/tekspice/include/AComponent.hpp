/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <iomanip>

#include "IComponent.hpp"
#include "Utilities.hpp"

#define print(x) nts::getStringFromTristate(x)

namespace nts {
    class AComponent : public nts::IComponent {
    public:
        AComponent();

        void assignPin(std::size_t id, nts::Tristate state, std::size_t tick);

        nts::Tristate getPinState(std::size_t pin) const override;

        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

        const std::vector<nts::pin_t> &getPins() const override;

        const nts::pin_t &getPin(std::size_t id) const override;

        void updatePin(std::size_t id, std::size_t tick) override;

    protected:
        std::vector<nts::pin_t> _totalPins;

    private:
    };
}

#endif /* !ACOMPONENT_HPP_ */
