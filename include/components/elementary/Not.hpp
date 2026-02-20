/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#ifndef NOTGATE_HPP
#define NOTGATE_HPP

#include <memory>
#include "AElementaryComponent.hpp"
#include "components/IComponent.hpp"

namespace nts {

class Not : public AElementaryComponent {
public:
    explicit Not(std::string name);
    static std::unique_ptr<IComponent> create(std::string name);
    Tristate compute(const std::size_t &pin) override;
private:
    std::vector<Tristate> _truthTable;
};
}
#endif

