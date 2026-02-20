/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** True
*/

#include "../include/True.hpp"

#include <memory>

namespace nts {
True::True(std::string name): ASpecialComponent{std::move(name)}
{
    _type            = TRUE_TYPE;
    _outputStates[0] = Tristate::TRUE;
    _pins[1]         = Pin{PinType::OUTPUT, nullptr, 0};
}

std::unique_ptr<IComponent> True::create(std::string name)
{
    return std::make_unique<True>(std::move(name));
}
} // nts
