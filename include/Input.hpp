/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Input
*/

#ifndef NANOTEKSPICE_INPUT_HPP
#define NANOTEKSPICE_INPUT_HPP

#include <memory>

#include "ASpecialComponent.hpp"

namespace nts {
class Input: public ASpecialComponent {
public:
    explicit Input(std::string name);

    ~Input() override = default;

    static std::unique_ptr<IComponent> create(std::string name);
};
} // nts

#endif //NANOTEKSPICE_INPUT_HPP