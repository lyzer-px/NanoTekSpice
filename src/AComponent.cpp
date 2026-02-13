/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AComponent
*/

#include "../include/AComponent.hpp"

#include <stdexcept>

namespace nts {
AComponent::AComponent(std::string name): _name{std::move(name)},
    _numberOfPin{1}, _tick{0}
{}

void AComponent::setLink(const std::size_t pin, IComponent &other,
    std::size_t otherPin)
{
    if (pin > _numberOfPin || _pins.at(pin).type != PinType::OUTPUT) {
        throw std::runtime_error("Bad pin number");
    }

    _pins[pin].linkedComponent = &other;
}

void AComponent::simulate(std::size_t tick)
{
    ++_tick;
}
} // nts
