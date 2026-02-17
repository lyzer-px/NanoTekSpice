/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Circuit
*/

#include "../include/Circuit.hpp"

#include <iostream>

namespace nts {
Circuit::Circuit(std::string name): AComponent{std::move(name)}
{}

void Circuit::simulate(const std::size_t &tick)
{
    ++_tick;

    for (const auto &chipset: _chipsets) {
        chipset->simulate(tick);
    }
}

Tristate Circuit::compute(const std::size_t &pin)
{
    if (pin > _numberOfPin || pin < 1 || _pins[pin].type != PinType::OUTPUT) {
        throw std::runtime_error("Bad pin number");
    }

    return Tristate::UNDEFINED;
}

void Circuit::setLink(const std::size_t &pin, IComponent &other,
    const std::size_t &otherPin)
{
    AComponent::setLink(pin, other, otherPin);
}

void Circuit::setChipset(
    std::vector<std::pair<Component, chipsetName>> &chipsets)
{
    for (const auto &[chipsetType, chipsetName]: chipsets) {
        try {
            auto component = _factory.create(chipsetType, chipsetName);

            if (chipsetType == INPUT_TYPE) {
                _inputs.push_back(component.get());
            }
            if (chipsetType == OUTPUT_TYPE) {
                _output.push_back(component.get());
            }
            _chipsets.push_back(std::move(component));

        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void Circuit::linkChipsets(std::vector<Link> &links)
{
    for (const auto &[node1, node2]: links) {
        auto chipset1 = std::ranges::find_if(_chipsets,
            [node1](const std::unique_ptr<IComponent> &chipset) {
                return node1.first == chipset->getName();
            }
            );
        auto chipset2 = std::ranges::find_if(_chipsets,
            [node2](const std::unique_ptr<IComponent> &chipset) {
                return node2.first == chipset->getName();
            }
            );

        if (chipset1 == _chipsets.end() || chipset2 == _chipsets.end()) {
            throw std::runtime_error("Unknown chipset");
        }

        chipset1->get()->setLink(node1.second, *(chipset2->get()),
            node2.second);
    }
}
} // nts
