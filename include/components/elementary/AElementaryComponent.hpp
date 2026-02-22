/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AElementaryComponent
*/

#ifndef NANOTEKSPICE_AELEMENTARYCOMPONENT_HPP
#define NANOTEKSPICE_AELEMENTARYCOMPONENT_HPP

#include <vector>

#include "../AComponent.hpp"

namespace nts {
class AElementaryComponent: public AComponent {
public:
    explicit AElementaryComponent(std::string name);
    
    Tristate compute(const std::size_t &pin) override;

    void simulate(const std::size_t &pin) override;

protected:
    std::vector<std::vector<Tristate>> _truthTable;
    bool _isComputing = false;
    bool _isSimulating = false;
};
} // nts

#endif //NANOTEKSPICE_AELEMENTARYCOMPONENT_HPP
