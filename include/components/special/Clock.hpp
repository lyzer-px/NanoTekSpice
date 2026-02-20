/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Clock
*/

#ifndef NANOTEKSPICE_CLOCK_HPP
#define NANOTEKSPICE_CLOCK_HPP
#include <memory>

#include "ASpecialComponent.hpp"

namespace nts {
class Clock: public ASpecialComponent {
public:
    explicit Clock(std::string name);

    ~Clock() override = default;

    void simulate(const std::size_t &tick) override;

    static std::unique_ptr<IComponent> create(std::string name);
};
} // nts

#endif //NANOTEKSPICE_CLOCK_HPP