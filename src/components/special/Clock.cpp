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
    _pins[1] = Pin{PinType::OUTPUT};
}

void Clock::simulate(const std::size_t &tick)
{
    if (_setState != Tristate::ERROR) {
        _outputStates[0] = _setState;
        _setState        = Tristate::ERROR;
    }

    if (tick > _tick && tick > 1 && _outputStates[0] != Tristate::UNDEFINED) {
        _outputStates[0] = _outputStates[0] == Tristate::TRUE ? Tristate::FALSE : Tristate::TRUE;
    }

    _tick = tick;
}

std::unique_ptr<IComponent> Clock::create(std::string name)
{
    return std::make_unique<Clock>(std::move(name));
}
} // nts
