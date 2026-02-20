/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Circuit
*/


#include <algorithm>
#include <iostream>
#include <ranges>

#include "components/IComponent.hpp"
#include "components/special/Clock.hpp"
#include "components/Circuit.hpp"
#include "parser/Parser.hpp"
#include "components/special/False.hpp"
#include "components/special/Input.hpp"
#include "components/special/Output.hpp"
#include "components/special/True.hpp"
#include "components/elementary/And.hpp"
#include "components/elementary/Or.hpp"
#include "components/elementary/Nor.hpp"
#include "components/elementary/Not.hpp"
#include "components/elementary/Xor.hpp"
#include "components/elementary/Xnor.hpp"
#include "components/elementary/Nand.hpp"


namespace nts {
Circuit::Circuit(std::string name): AComponent{std::move(name)}
{
    _factory.registerCreator<Input>(INPUT_TYPE);
    _factory.registerCreator<Output>(OUTPUT_TYPE);
    _factory.registerCreator<True>(TRUE_TYPE);
    _factory.registerCreator<False>(FALSE_TYPE);
    _factory.registerCreator<Clock>(CLOCK_TYPE);
    _factory.registerCreator<And>(AND_TYPE);
    _factory.registerCreator<Nand>(NAND_TYPE);
    _factory.registerCreator<Or>(OR_TYPE);
    _factory.registerCreator<Xor>(XOR_TYPE);
    _factory.registerCreator<Xnor>(XNOR_TYPE);
    _factory.registerCreator<Not>(NOT_TYPE);
}

void Circuit::simulate(const std::size_t &tick)
{
    ++_tick;

    for (const auto &chipset: _output) {
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

            saveIfInputOrOutput(chipsetType, component.get());

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

        chipset1->get()->setLink(node1.second, **chipset2, node2.second);
    }
}

void Circuit::setInput(const ChipsetName &chipsetName, const std::string &value)
{
    const auto temp = std::ranges::find_if(_chipsets,
        [chipsetName](const std::unique_ptr<IComponent> &component) {
            return component->getName() == chipsetName;
        });

    if (temp == _chipsets.end()) {
        throw std::runtime_error("Unknown chipset: " + chipsetName);
    }

    try {
        (*temp)->setState(fromStringToTristate(value));
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Circuit::saveIfInputOrOutput(const ChipsetType &chipsetType,
    IComponent *chipset)
{
    if (chipsetType == INPUT_TYPE || chipsetType == TRUE_TYPE ||
        chipsetType == FALSE_TYPE || chipsetType == CLOCK_TYPE) {
        _inputs.push_back(chipset);
    }
    if (chipsetType == OUTPUT_TYPE) {
        _output.push_back(chipset);
    }
}
} // nts
