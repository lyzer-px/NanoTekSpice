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
#include "Parser.hpp"

namespace nts {
using ComponentFactory = FactoryTemplate<IComponent, ChipsetType, ChipsetName>;

class Circuit: public AComponent {
public:
    explicit Circuit(std::string name);

    void simulate(const std::size_t &tick) override;

    Tristate compute(const std::size_t &pin) override;

    void setLink(const std::size_t &pin, IComponent &other,
        const std::size_t &otherPin) override;

    void setChipset(
        std::vector<std::pair<ChipsetType, ChipsetName>> &&chipsets);

    void linkChipsets(std::vector<Link> &&links);

private:
    std::vector<IComponent *> _inputs;
    std::vector<IComponent *> _output;
    std::vector<std::unique_ptr<IComponent>> _chipsets;
    ComponentFactory _factory;

    void saveIfInputOrOutput(const ChipsetType &chipsetType,
        IComponent *chipset);
};

}
#endif
