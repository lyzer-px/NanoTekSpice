/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Output
*/

#ifndef NANOTEKSPICE_OUTPUT_HPP
#define NANOTEKSPICE_OUTPUT_HPP

#include "ASpecialComponent.hpp"

namespace nts {
class Output: public ASpecialComponent {
public:
    explicit Output(std::string name);

    ~Output() override = default;
};
} // nts

#endif //NANOTEKSPICE_OUTPUT_HPP