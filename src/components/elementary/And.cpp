/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "components/elementary/And.hpp"
#include <memory>
#include <string>

namespace nts {

And::And(std::string name) : AElementaryComponent(std::move(name)) {
        this->_type = AND_TYPE;
        this->_truthTable = {
            {Tristate::FALSE, Tristate::FALSE, Tristate::UNDEFINED},
            {Tristate::FALSE, Tristate::TRUE, Tristate::UNDEFINED},
            {Tristate::UNDEFINED, Tristate::UNDEFINED, Tristate::UNDEFINED},
        };
    }

std::unique_ptr<IComponent> And::create(std::string name)
{
    return std::make_unique<And>(std::move(name));    
}




}
