/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef XORGATE_HPP
#define XORGATE_HPP

#include <memory>
#include "AElementaryComponent.hpp"
#include "components/IComponent.hpp"

namespace nts {

class Xor : public AElementaryComponent {
public:
    explicit Xor(std::string name);
    static std::unique_ptr<IComponent> create(std::string name);
};
}
#endif

