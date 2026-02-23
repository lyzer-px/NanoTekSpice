/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "components/elementary/Xor.hpp"
#include <memory>
#include <string>

namespace nts {

Xor::Xor(std::string name) : AElementaryComponent(std::move(name)) {
        this->_type = XOR_TYPE;
        this->_truthTable = {
            {Tristate::FALSE, Tristate::TRUE, Tristate::UNDEFINED},
            {Tristate::TRUE, Tristate::FALSE, Tristate::TRUE},
            {Tristate::UNDEFINED, Tristate::TRUE, Tristate::UNDEFINED},
        };
    }

std::unique_ptr<IComponent> Xor::create(std::string name)
{
    return std::make_unique<Xor>(std::move(name));    
}

}
