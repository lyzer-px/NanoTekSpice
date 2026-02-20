/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Input
*/

#include "../include/Input.hpp"

namespace nts {
Input::Input(std::string name): ASpecialComponent{std::move(name)}
{
    _type    = INPUT_TYPE;
    _pins[1] = Pin{PinType::OUTPUT, nullptr, 0};
}

std::unique_ptr<IComponent> Input::create(std::string name)
{
    return std::make_unique<Input>(std::move(name));
}
} // nts
