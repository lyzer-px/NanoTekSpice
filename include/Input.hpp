/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Input
*/

#ifndef NANOTEKSPICE_INPUT_HPP
#define NANOTEKSPICE_INPUT_HPP

#include "ASpecialComponent.hpp"

namespace nts {
class Input: public ASpecialComponent {
public:
    explicit Input(std::string name);

    ~Input() override = default;
};
} // nts

#endif //NANOTEKSPICE_INPUT_HPP