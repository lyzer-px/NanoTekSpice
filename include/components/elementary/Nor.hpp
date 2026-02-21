/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef NORGATE_HPP
#define NORGATE_HPP

#include <memory>
#include "AElementaryComponent.hpp"
#include "components/IComponent.hpp"

namespace nts {

class Nor : public AElementaryComponent {
public:
    explicit Nor(std::string name);
    static std::unique_ptr<IComponent> create(std::string name);
};
}
#endif

