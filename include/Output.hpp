/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Output
*/

#ifndef NANOTEKSPICE_OUTPUT_HPP
#define NANOTEKSPICE_OUTPUT_HPP

#include <memory>
#include <stdexcept>

#include "ASpecialComponent.hpp"

namespace nts {
class Output: public ASpecialComponent {
public:
    explicit Output(std::string name);

    ~Output() override = default;

    static std::unique_ptr<IComponent> create(std::string name);

    Tristate compute(const std::size_t &pin) override;
};
} // nts

#endif //NANOTEKSPICE_OUTPUT_HPP