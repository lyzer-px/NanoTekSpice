/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ASpecialComponent
*/

#include "components/special/ASpecialComponent.hpp"

#include <stdexcept>

namespace nts {
ASpecialComponent::ASpecialComponent(std::string name):
    AComponent(std::move(name))
{
    _numberOfPin = 1;
    _outputStates.push_back(Tristate::UNDEFINED);
}

Tristate ASpecialComponent::compute(const std::size_t &)
{
    return _outputStates[0];
}

void ASpecialComponent::setState(const Tristate &state)
{
    if (_type == INPUT_TYPE || _type == CLOCK_TYPE) {
        _setState = state;
        return;
    }

    throw std::runtime_error("Cannot set state for this component");
}

void ASpecialComponent::simulate(const std::size_t &tick)
{
    if (_setState != Tristate::ERROR) {
        _outputStates[0] = _setState;
        _setState        = Tristate::ERROR;
        // if (_pins[1].linkedComponent != nullptr)
        //     _pins[1].linkedComponent->simulate(tick);
    }

    AComponent::simulate(tick);
}
} // namespace nts
