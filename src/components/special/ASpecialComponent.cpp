/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ASpecialComponent
*/

#include "components/special/ASpecialComponent.hpp"

namespace nts {
ASpecialComponent::ASpecialComponent(std::string name): AComponent(
    std::move(name))
{
    _numberOfPin = 1;
    _outputStates.reserve(1);
    _outputStates[0] = Tristate::UNDEFINED;
}

Tristate ASpecialComponent::compute(const std::size_t &)
{
    return _outputStates[0];
}
} // nts
