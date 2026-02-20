/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef ANDGATE_HPP
#define ANDGATE_HPP

#include <memory>
#include "AElementaryComponent.hpp"
#include "components/IComponent.hpp"

namespace nts {

class Or : public AElementaryComponent {
public:
    explicit Or(std::string name);
    static std::unique_ptr<IComponent> create(std::string name);
};
}
#endif

