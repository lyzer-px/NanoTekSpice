/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AElementaryComponent
*/

#include "../include/AElementaryComponent.hpp"

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

    const Tristate input1 = _pins[pin].linkedComponent->compute(1);
    const Tristate input2 = _pins[pin].linkedComponent->compute(2);

    return _truthTable[input1][input2];
}
} // nts
