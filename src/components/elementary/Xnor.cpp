/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "components/elementary/Xnor.hpp"
#include <memory>
#include <string>

namespace nts {

Xnor::Xnor(std::string name) : AElementaryComponent(std::move(name)) {
        this->_type = XNOR_TYPE;
        this->_truthTable = {
            {Tristate::TRUE, Tristate::FALSE, Tristate::UNDEFINED},
            {Tristate::FALSE, Tristate::TRUE, Tristate::UNDEFINED},
            {Tristate::UNDEFINED, Tristate::UNDEFINED, Tristate::UNDEFINED},
        };
    }

std::unique_ptr<IComponent> Xnor::create(std::string name)
{
    return std::make_unique<Xnor>(std::move(name));    
}

}
