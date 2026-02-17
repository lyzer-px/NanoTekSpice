/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** True
*/

#ifndef NANOTEKSPICE_TRUE_HPP
#define NANOTEKSPICE_TRUE_HPP

#include "ASpecialComponent.hpp"

namespace nts {
class True: public ASpecialComponent {
public:
    explicit True(std::string name);
};
} // nts

#endif //NANOTEKSPICE_TRUE_HPP