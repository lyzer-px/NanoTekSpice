/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Circuit
*/

#ifndef NANOTEKSPICE_CIRCUIT_HPP
#define NANOTEKSPICE_CIRCUIT_HPP

#include <memory>
#include <vector>

#include "AComponent.hpp"
#include "FactoryTemplate.hpp"

namespace nts {
using chipsetName      = std::string;
using chipsetType      = std::string;
using pin              = std::size_t;
using Component        = std::string;
using token            = std::string;
using ComponentFactory = FactoryTemplate<IComponent, chipsetType, chipsetName>;

struct Link {
    std::pair<chipsetName, pin> component1;
    std::pair<chipsetName, pin> component2;
};

class Circuit: public AComponent {
public:
    explicit Circuit(std::string name);

    void simulate(const std::size_t &tick) override;

    Tristate compute(const std::size_t &pin) override;

    void setLink(const std::size_t &pin, IComponent &other,
        const std::size_t &otherPin) override;

    void setChipset(std::vector<std::pair<Component, chipsetName>> &chipsets);

    void linkChipsets(std::vector<Link> &links);

private:
    std::vector<IComponent *> _inputs;
    std::vector<IComponent *> _output;
    std::vector<std::unique_ptr<IComponent>> _chipsets;
    ComponentFactory _factory;
};
} // nts

#endif //NANOTEKSPICE_CIRCUIT_HPP