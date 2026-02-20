/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** True
*/

#ifndef NANOTEKSPICE_TRUE_HPP
#define NANOTEKSPICE_TRUE_HPP

#include <memory>

#include "ASpecialComponent.hpp"

namespace nts {
class True: public ASpecialComponent {
public:
    explicit True(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};
} // nts

#endif //NANOTEKSPICE_TRUE_HPP