/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ASpecialComponent
*/

#include "ASpecialComponent.hpp"

namespace nts {
ASpecialComponent::ASpecialComponent(std::string name): AComponent(
    std::move(name)), _value{UNDEFINED}
{
    _numberOfPin = 1;
}

Tristate ASpecialComponent::compute(const std::size_t &)
{
    return _value;
}
} // nts
