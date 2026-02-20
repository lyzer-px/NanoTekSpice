/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "components/elementary/Or.hpp"
#include <memory>
#include <string>

namespace nts {

Or::Or(std::string name) : AElementaryComponent(std::move(name)) {
        this->_type = AND_TYPE;
        this->_truthTable = {
            {Tristate::FALSE, Tristate::TRUE, Tristate::UNDEFINED},
            {Tristate::TRUE, Tristate::TRUE, Tristate::UNDEFINED},
            {Tristate::UNDEFINED, Tristate::UNDEFINED, Tristate::UNDEFINED},
        };
    }

std::unique_ptr<IComponent> Or::create(std::string name)
{
    return std::make_unique<Or>(std::move(name));    
}

}
