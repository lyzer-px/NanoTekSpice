/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef XNORGATE_HPP
#define XNORGATE_HPP

#include <memory>
#include "AElementaryComponent.hpp"
#include "components/IComponent.hpp"

namespace nts {

class Xnor : public AElementaryComponent {
public:
    explicit Xnor(std::string name);
    static std::unique_ptr<IComponent> create(std::string name);
};
}
#endif

