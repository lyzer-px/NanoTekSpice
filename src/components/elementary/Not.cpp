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
        this->_type = NOR_TYPE;
        this->_truthTable = {Tristate::TRUE, Tristate::FALSE, Tristate::UNDEFINED};
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
    if (this->_pins[1].linkedComponent == nullptr)
        throw std::logic_error("Not gate not linked");
    input = this->_pins[1].linkedComponent->compute(this->_pins[1].pin);
    return this->_truthTable[input];
}

}
