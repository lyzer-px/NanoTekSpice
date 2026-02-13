/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Output
*/

#include "../include/Output.hpp"

namespace nts {
Output::Output(std::string name): ASpecialComponent(std::move(name))
{
    _type    = OUTPUT_TYPE;
    _value   = Tristate::UNDEFINED;
    _pins[1] = Pin{PinType::INPUT, nullptr, 0};
}
} // nts
