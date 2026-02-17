/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** True
*/

#include "../include/True.hpp"

namespace nts {
True::True(std::string name): ASpecialComponent{std::move(name)}
{
    _type    = TRUE_TYPE;
    _value   = Tristate::TRUE;
    _pins[1] = Pin{PinType::OUTPUT, nullptr, 0};
}
} // nts
