/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ASpecialComponent
*/

#ifndef NANOTEKSPICE_ASPECIALCOMPONENT_HPP
#define NANOTEKSPICE_ASPECIALCOMPONENT_HPP

#include "../AComponent.hpp"

namespace nts {
class ASpecialComponent: public AComponent {
public:
    explicit ASpecialComponent(std::string name);

    Tristate compute(const std::size_t &pin) override;

    void setState(const Tristate &state) override;

    void simulate(const std::size_t &tick) override;

protected:
    Tristate _setState = Tristate::ERROR;
};
} // nts

#endif //NANOTEKSPICE_ASPECIALCOMPONENT_HPP
