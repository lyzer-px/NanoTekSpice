/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "components/elementary/Nor.hpp"
#include <memory>
#include <string>

namespace nts {

Nor::Nor(std::string name) : AElementaryComponent(std::move(name)) {
        this->_type = NOR_TYPE;
        this->_truthTable = {
            {Tristate::TRUE, Tristate::FALSE, Tristate::UNDEFINED},
            {Tristate::FALSE, Tristate::FALSE, Tristate::FALSE},
            {Tristate::UNDEFINED, Tristate::FALSE, Tristate::UNDEFINED},
        };
    }

std::unique_ptr<IComponent> Nor::create(std::string name)
{
    return std::make_unique<Nor>(std::move(name));    
}

}
