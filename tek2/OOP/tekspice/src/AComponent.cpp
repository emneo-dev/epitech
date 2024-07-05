/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-alexandre.flion
** File description:
** AComponent
*/

#include "Errors.hpp"
#include "AComponent.hpp"

namespace nts {
    AComponent::AComponent() = default;

    void AComponent::assignPin(std::size_t id, nts::Tristate state, std::size_t tick) {
        for (auto & totalPin : _totalPins)
            if (id == totalPin.id) {
                totalPin.lastTickSimulated = tick;
                totalPin.state = state;
                return;
            }
        throw PinNumberUnknown();
    }

    // TODO: I felt bad writing this, and I sure hope that I don't need to come back fix this
    void AComponent::updatePin(std::size_t id, std::size_t tick) {
        const auto pin = getPin(id);
        if (pin.lastTickSimulated != tick) {
            if (pin.linkedComponent != nullptr) {
                //getPin(id).linkedComponent->simulate(tick);
                pin.linkedComponent->updatePin(pin.linkedPin, tick);
                assignPin(id, pin.linkedComponent->getPin(getPin(id).linkedPin).state, tick);
            } else {
                assignPin(id, nts::Tristate::UNDEFINED, tick);
            }
        }
    }

    const nts::pin_t &AComponent::getPin(std::size_t id) const {
        for (const auto & totalPin : _totalPins)
            if (id == totalPin.id)
                return totalPin;
        throw PinNumberUnknown();
    }

    nts::Tristate AComponent::getPinState(std::size_t pin) const {
        for (const auto & totalPin : _totalPins)
            if (pin == totalPin.id)
                return (totalPin.state);
        throw PinNumberUnknown();
    }

    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        for (auto & totalPin : _totalPins)
            if (pin == totalPin.id) {
                totalPin.linkedComponent = &other;
                totalPin.linkedPin = otherPin;
                return;
            }
        throw PinNumberUnknown();
    }

    const std::vector<nts::pin_t> &AComponent::getPins() const {
        return _totalPins;
    }
}