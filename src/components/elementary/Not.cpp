/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "components/elementary/Not.hpp"
#include <memory>
#include <stdexcept>
#include <string>

namespace nts {

Not::Not(std::string name) : AElementaryComponent(std::move(name)) {
    this->_type = NOT_TYPE;
    this->_truthTable = {Tristate::TRUE, Tristate::FALSE, Tristate::UNDEFINED};
    this->_pins[1] = Pin(PinType::INPUT, nullptr, 0);
    this->_pins[2] = Pin(PinType::OUTPUT, nullptr, 0);
}

std::unique_ptr<IComponent> Not::create(std::string name)
{
    return std::make_unique<Not>(std::move(name));    
}

Tristate Not::compute(const std::size_t &pin)
{
    if (pin != 2) 
        throw std::logic_error("Invalid pin for Not gate");
    Tristate input = Tristate::UNDEFINED;
    if (this->_pins[1].linkedComponent != nullptr)
        input = this->_pins[1].linkedComponent->compute(this->_pins[1].pin);
    return this->_truthTable[input];
}

}
