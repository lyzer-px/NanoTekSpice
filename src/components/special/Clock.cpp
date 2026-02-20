/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Clock
*/

#include "components/special/Clock.hpp"

namespace nts {
Clock::Clock(std::string name): ASpecialComponent{std::move(name)}
{
    _type    = CLOCK_TYPE;
    _pins[1] = Pin{PinType::OUTPUT, nullptr, 0};
}

void Clock::simulate(const std::size_t &tick)
{
    if (tick > _tick && _outputStates[0] != Tristate::UNDEFINED) {
        _outputStates[0] = static_cast<Tristate>(!static_cast<bool>(
            _outputStates[0]));
    }

    _tick = tick;
}

std::unique_ptr<IComponent> Clock::create(std::string name)
{
    return std::make_unique<Clock>(std::move(name));
}
} // nts
