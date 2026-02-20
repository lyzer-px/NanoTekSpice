/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef NANDGATE_HPP
#define NANDGATE_HPP

#include <memory>
#include "AElementaryComponent.hpp"
#include "components/IComponent.hpp"

namespace nts {

class Nand : public AElementaryComponent {
public:
    explicit Nand(std::string name);
    static std::unique_ptr<IComponent> create(std::string name);
};
}
#endif
