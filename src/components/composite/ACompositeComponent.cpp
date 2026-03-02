/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ACompositeComponent
*/

#include "../../../include/components/composite/ACompositeComponent.hpp"

#include <stdexcept>

namespace nts {
ACompositeComponent::ACompositeComponent(std::string name):
    AComponent{std::move(name)}
{
    _numberOfPin = 14;
}

Tristate ACompositeComponent::compute(const std::size_t &pin)
{
    if (pin > _numberOfPin || pin < 1 || _pins[pin].type != PinType::OUTPUT)
        throw std::runtime_error("Bad pin number");

    auto &[component, componentPin] = _internalPins[pin][0];

    return component->compute(componentPin);
}

void ACompositeComponent::setLink(
    const std::size_t &pin, IComponent &other, const std::size_t &otherPin)
{
    if (pin > _numberOfPin || pin < 1 || _pins[pin].type == PinType::POWER)
        throw std::runtime_error("Bad pin number");

    if (_pins[pin].type == PinType::INPUT) {
        auto &nodes = _internalPins[pin];
        for (auto &[component, componentPin] : nodes)
            component->setLink(componentPin, other, otherPin);
    } else {
        if (getPinType(otherPin, other) == PinType::OUTPUT)
            throw std::runtime_error("Can not connect two pin of same type");

        other.setLink(otherPin, *this, pin);
    }
}

void ACompositeComponent::registerInternComponentsPins()
{
    _internalPins[1]  = {std::pair{_components[0].get(), 1}};
    _internalPins[2]  = {std::pair{_components[0].get(), 2}};
    _internalPins[3]  = {std::pair{_components[0].get(), 3}};
    _internalPins[4]  = {std::pair{_components[1].get(), 3}};
    _internalPins[5]  = {std::pair{_components[1].get(), 1}};
    _internalPins[6]  = {std::pair{_components[1].get(), 2}};
    _internalPins[7]  = {};
    _internalPins[8]  = {std::pair{_components[2].get(), 1}};
    _internalPins[9]  = {std::pair{_components[2].get(), 2}};
    _internalPins[10] = {std::pair{_components[3].get(), 3}};
    _internalPins[11] = {std::pair{_components[3].get(), 3}};
    _internalPins[12] = {std::pair{_components[3].get(), 1}};
    _internalPins[13] = {std::pair{_components[3].get(), 2}};
    _internalPins[14] = {};
}

void ACompositeComponent::setPinsType()
{
    for (const auto &pin: {1, 2, 5, 6, 8, 9, 12, 13})
        _pins[pin] = Pin{PinType::INPUT};

    for (const auto &pin: {3, 4, 10, 11})
        _pins[pin] = Pin{PinType::OUTPUT};

    _pins[7] = _pins[14] = Pin{PinType::POWER};
}
} // namespace nts
