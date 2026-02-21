/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AComponent
*/

#include "components/AComponent.hpp"

#include <ostream>
#include <ranges>
#include <stdexcept>

namespace nts {
Pin::Pin(): type{PinType::INPUT}, linkedComponent{nullptr}, pin{0}
{}

Pin::Pin(const PinType &pinType, IComponent *component,
    const std::size_t &pinNumber): type{pinType}, linkedComponent{component},
    pin{pinNumber}
{}
Pin::Pin(const PinType &pinType): type{pinType}, linkedComponent{nullptr},
    pin{0}
{}

AComponent::AComponent(std::string name): _name{std::move(name)},
    _numberOfPin{1}, _tick{0}
{}

void AComponent::setLink(const std::size_t &pin, IComponent &other,
    const std::size_t &otherPin)
{
    if (pin > _numberOfPin || pin < 1)
        throw std::runtime_error("Bad pin number");

    if (_pins[pin].type == PinType::INPUT) {
        _pins[pin].linkedComponent = &other;
        _pins[pin].pin             = otherPin;
    } else {
        if (getPinType(otherPin, other) == PinType::OUTPUT) {
            throw std::runtime_error("Can not connect two pin of same type");
        }

        other.setLink(otherPin, *this, pin);
    }
}

Tristate AComponent::fromStringToTristate(const std::string &value)
{
    if (value == "0")
        return Tristate::FALSE;
    if (value == "1")
        return Tristate::TRUE;
    if (value == "U")
        return Tristate::UNDEFINED;
    throw std::runtime_error("Unknown state value: " + value);
}

void AComponent::simulate(const std::size_t &tick)
{
    _tick = tick;

    for (const auto &pin: _pins | std::views::values) {
        if (pin.type == PinType::INPUT && pin.linkedComponent != nullptr)
            pin.linkedComponent->simulate(tick);
    }
}

PinType AComponent::getPinType(const std::size_t &pin,
    IComponent &component)
{
    auto &temp = dynamic_cast<AComponent &>(component);

    return temp._pins[pin].type;
}

std::string AComponent::getName() const noexcept
{
    return _name;
}

void AComponent::setState(const Tristate &state)
{
    if (_type == INPUT_TYPE || _type == CLOCK_TYPE) {
        _outputStates[0] = state;
        return;
    }

    throw std::runtime_error("Cannot set state for this component");
}
} // nts

std::ostream &operator<<(std::ostream &outStream, const nts::Tristate &state)
{
    switch (static_cast<int>(state)) {
    case nts::Tristate::FALSE:
        outStream << "0";
        break;
    case nts::Tristate::TRUE:
        outStream << "1";
        break;
    case nts::Tristate::UNDEFINED:
        outStream << "U";
    default:
        break;
    }

    return outStream;
}
