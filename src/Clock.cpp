/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Clock
*/

#include "Clock.hpp"

namespace nts {
Clock::Clock(std::string name): ASpecialComponent{std::move(name)}
{
    _type    = CLOCK_TYPE;
    _value   = Tristate::UNDEFINED;
    _pins[1] = Pin{PinType::OUTPUT, nullptr, 0};
}

void Clock::simulate(const std::size_t &tick)
{
    if (tick > _tick && _value != Tristate::UNDEFINED) {
        _value = static_cast<Tristate>(!static_cast<bool>(_value));
    }

    _tick = tick;
}
} // nts
