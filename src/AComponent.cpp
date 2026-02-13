/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AComponent
*/

#include "../include/AComponent.hpp"

#include <stdexcept>

namespace nts {
Pin::Pin(): type{PinType::INPUT}, linkedComponent{nullptr}, pin{0}
{}

Pin::Pin(const PinType &pinType, IComponent *component,
    const std::size_t &pinNumber): type{pinType}, linkedComponent{component},
    pin{pinNumber}
{}

AComponent::AComponent(std::string name): _name{std::move(name)},
    _numberOfPin{1},
    _tick{0}
{}

void AComponent::setLink(const std::size_t &pin, IComponent &other,
    const std::size_t &)
{
    if (pin > _numberOfPin || _pins.at(pin).type != PinType::OUTPUT) {
        throw std::runtime_error("Bad pin number");
    }

    _pins[pin].linkedComponent = &other;
}

void AComponent::simulate(const std::size_t &)
{
    ++_tick;
}
} // nts
