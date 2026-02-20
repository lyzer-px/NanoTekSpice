/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AElementaryComponent
*/

#include "components/elementary/AElementaryComponent.hpp"

#include <stdexcept>

namespace nts {
AElementaryComponent::AElementaryComponent(std::string name): AComponent{
    std::move(name)}
{
    _numberOfPin = 3;
    _pins[1]     = Pin{PinType::INPUT, nullptr, 0};
    _pins[2]     = Pin{PinType::INPUT, nullptr, 0};
    _pins[3]     = Pin{PinType::OUTPUT, nullptr, 0};
}

Tristate AElementaryComponent::compute(const std::size_t &pin)
{
    if (pin > _numberOfPin || pin < 1 || _pins[pin].type != PinType::OUTPUT) {
        throw std::runtime_error("Bad pin number");
    }

    Tristate input1 = Tristate::UNDEFINED;
    Tristate input2 = Tristate::UNDEFINED;

    if (_pins[1].linkedComponent != nullptr)
        input1 = _pins[1].linkedComponent->compute(1);
    if (_pins[2].linkedComponent != nullptr)
        input2 = _pins[2].linkedComponent->compute(2);

    return _truthTable[input1][input2];
}
} // nts
