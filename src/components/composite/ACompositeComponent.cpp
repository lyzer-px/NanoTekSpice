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
    if (pin > _numberOfPin || pin < 1 || _pins[pin].type == PinType::INPUT)
        throw std::runtime_error("Bad pin number");

    auto &[component, componentPin] = _inputPins[pin];

    return component->compute(componentPin);
}

void ACompositeComponent::setLink(
    const std::size_t &pin, IComponent &other, const std::size_t &otherPin)
{
    if (pin > _numberOfPin || pin < 1 || _pins[pin].type == PinType::POWER)
        throw std::runtime_error("Bad pin number");

    if (_pins[pin].type == PinType::INPUT) {
        auto &[component, componentPin] = _inputPins[pin];
        component->setLink(componentPin, other, otherPin);
    } else {
        if (getPinType(otherPin, other) == PinType::OUTPUT) {
            throw std::runtime_error("Can not connect two pin of same type");
        }

        other.setLink(otherPin, *this, pin);
    }
}
void ACompositeComponent::registerInternComponentsPins()
{
    _inputPins[1]  = std::pair{_components[0].get(), 1};
    _inputPins[2]  = std::pair{_components[0].get(), 2};
    _inputPins[3]  = std::pair{_components[0].get(), 3};
    _inputPins[4]  = std::pair{_components[1].get(), 3};
    _inputPins[5]  = std::pair{_components[1].get(), 1};
    _inputPins[6]  = std::pair{_components[1].get(), 2};
    _inputPins[7]  = std::pair{nullptr, 0};
    _inputPins[8]  = std::pair{_components[2].get(), 1};
    _inputPins[9]  = std::pair{_components[2].get(), 2};
    _inputPins[10] = std::pair{_components[3].get(), 3};
    _inputPins[11] = std::pair{_components[3].get(), 3};
    _inputPins[12] = std::pair{_components[3].get(), 1};
    _inputPins[13] = std::pair{_components[3].get(), 2};
    _inputPins[14] = std::pair{nullptr, 0};
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
