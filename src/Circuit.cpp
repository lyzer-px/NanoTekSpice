/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Circuit
*/

#include "../include/Circuit.hpp"

#include <algorithm>
#include <iostream>
#include <ranges>
#include "Parser.hpp"

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

Tristate Circuit::compute(const std::size_t &)
{
    std::cout << "tick: " << _tick << std::endl;

    std::cout << "input(s): " << std::endl;
    for (const auto &input: _inputs) {
        std::cout << "  " << input->getName() << ": " << input->compute(1) <<
            std::endl;
    }

    std::cout << "output(s): " << std::endl;
    for (const auto &output: _output) {
        std::cout << "  " << output->getName() << ": " << output->compute(1) <<
            std::endl;
    }

    return Tristate::UNDEFINED;
}

void Circuit::setLink(const std::size_t &pin, IComponent &other,
    const std::size_t &otherPin)
{
    AComponent::setLink(pin, other, otherPin);
}

void Circuit::setChipset(
    std::vector<std::pair<ChipsetType, ChipsetName>> &&chipsets)
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

    std::ranges::sort(_inputs,
        [](const IComponent *input1, const IComponent *input2) {
            return input1->getName() < input2->getName();
        });
    std::ranges::sort(_output,
        [](const IComponent *input1, const IComponent *input2) {
            return input1->getName() < input2->getName();
        });
}

void Circuit::linkChipsets(std::vector<Link> &&links)
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
