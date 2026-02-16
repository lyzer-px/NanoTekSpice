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
    const std::size_t & otherPin)
{
    if (pin > _numberOfPin) {
        throw std::runtime_error("Bad pin number");
    }

    if (_pins[pin].type == PinType::INPUT) {
        _pins[pin].linkedComponent = &other;
        _pins[pin].pin = otherPin;
    } else {
        if (getPinType(otherPin, other) == PinType::OUTPUT) {
            throw std::runtime_error("Can not connect two pin of same type");
        }

        other.setLink(otherPin, *this, pin);
    }
}

void AComponent::simulate(const std::size_t &)
{
    ++_tick;
}

PinType AComponent::getPinType(const std::size_t &pin,
    IComponent &component)
{
    auto &temp = dynamic_cast<AComponent &>(component);

    return temp._pins[pin].type;
}
} // nts
