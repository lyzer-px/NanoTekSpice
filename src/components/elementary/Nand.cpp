/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "components/elementary/Nand.hpp"
#include <memory>
#include <string>

namespace nts {

Nand::Nand(std::string name) : AElementaryComponent(std::move(name)) {
        this->_type = NAND_TYPE;
        this->_truthTable = {
            {Tristate::TRUE, Tristate::FALSE, Tristate::UNDEFINED},
            {Tristate::FALSE, Tristate::TRUE, Tristate::UNDEFINED},
            {Tristate::UNDEFINED, Tristate::UNDEFINED, Tristate::UNDEFINED},
        };
    }

std::unique_ptr<IComponent> Nand::create(std::string name)
{
    return std::make_unique<Nand>(std::move(name));    
}




}
