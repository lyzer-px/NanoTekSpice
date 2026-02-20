/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** False
*/

#include "components/special/False.hpp"

namespace nts {
False::False(std::string name): ASpecialComponent{std::move(name)}
{
    _type            = FALSE_TYPE;
    _outputStates[0] = Tristate::FALSE;
    _pins[1]         = Pin{PinType::OUTPUT, nullptr, 0};
}

std::unique_ptr<IComponent> False::create(std::string name)
{
    return std::make_unique<False>(std::move(name));
}
} // nts
