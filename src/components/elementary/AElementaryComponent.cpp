/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AElementaryComponent
*/

#include "components/elementary/AElementaryComponent.hpp"

#include <stdexcept>

namespace nts {
AElementaryComponent::AElementaryComponent(std::string name):
    AComponent{std::move(name)}
{
    _numberOfPin = 3;
    _pins[1]     = Pin{PinType::INPUT};
    _pins[2]     = Pin{PinType::INPUT};
    _pins[3]     = Pin{PinType::OUTPUT};
    _outputStates.resize(1);
    _outputStates[0] = Tristate::UNDEFINED;
}

Tristate AElementaryComponent::compute(const std::size_t &pin)
{
    if (pin > _numberOfPin || pin < 1 || _pins[pin].type != PinType::OUTPUT) {
        throw std::runtime_error("Bad pin number");
    }

    if (_isComputing)
        return _outputStates[0];

    _isComputing = true;

    Tristate input1 = Tristate::UNDEFINED;
    Tristate input2 = Tristate::UNDEFINED;

    if (_pins[1].linkedComponent != nullptr)
        input1 = _pins[1].linkedComponent->compute(_pins[1].pin);
    if (_pins[2].linkedComponent != nullptr)
        input2 = _pins[2].linkedComponent->compute(_pins[2].pin);

    _outputStates[0] = _truthTable[input1][input2];

    _isComputing = false;

    return _outputStates[0];
}
void AElementaryComponent::simulate(const std::size_t &pin)
{
    if (_isSimulating)
        return;

    _isSimulating = true;
    AComponent::simulate(pin);
    _isSimulating = false;
}
} // namespace nts
