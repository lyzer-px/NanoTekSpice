/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Clock
*/

#ifndef NANOTEKSPICE_CLOCK_HPP
#define NANOTEKSPICE_CLOCK_HPP
#include "ASpecialComponent.hpp"

namespace nts {
class Clock: public ASpecialComponent {
public:
    explicit Clock(std::string name);

    ~Clock() override = default;

    void simulate(const std::size_t &tick) override;
};
} // nts

#endif //NANOTEKSPICE_CLOCK_HPP