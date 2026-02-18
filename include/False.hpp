/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** False
*/

#ifndef NANOTEKSPICE_FALSE_HPP
#define NANOTEKSPICE_FALSE_HPP

#include <memory>

#include "ASpecialComponent.hpp"

namespace nts {
class False: public ASpecialComponent {
public:
    explicit False(std::string name);

    static std::unique_ptr<IComponent> create(std::string name);
};
} // nts

#endif //NANOTEKSPICE_FALSE_HPP