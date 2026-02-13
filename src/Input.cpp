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
    _type = INPUT_TYPE;
    _value = UNDEFINED;
    _pins[1] = Pin{PinType::INPUT, nullptr, 0};
}
} // nts