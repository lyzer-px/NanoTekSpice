/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Output
*/

#include "components/special/Output.hpp"

namespace nts {
Output::Output(std::string name): ASpecialComponent(std::move(name))
{
    _type    = OUTPUT_TYPE;
    _pins[1] = Pin{PinType::INPUT};
}

std::unique_ptr<IComponent> Output::create(std::string name)
{
    return std::make_unique<Output>(std::move(name));
}

Tristate Output::compute(const std::size_t &pin)
{
    if (pin != 1) {
        throw std::invalid_argument("compute3 -> Bad pin number");
    }

    if (_pins[pin].linkedComponent != nullptr)
        return _pins[pin].linkedComponent->compute(_pins[pin].pin);
    return Tristate::UNDEFINED;
}
} // nts
