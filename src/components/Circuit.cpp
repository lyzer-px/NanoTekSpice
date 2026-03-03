/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Circuit
*/

#include "components/Circuit.hpp"

#include <algorithm>
#include <iostream>
#include <ranges>

#include "components/composite/FourAnd.hpp"
#include "components/composite/FourNand.hpp"
#include "components/composite/FourOr.hpp"
#include "components/composite/FourNor.hpp"
#include "components/composite/FourXor.hpp"
#include "components/composite/SixInverter.hpp"
#include "components/elementary/And.hpp"
#include "components/elementary/Nand.hpp"
#include "components/elementary/Nor.hpp"
#include "components/elementary/Not.hpp"
#include "components/elementary/Or.hpp"
#include "components/elementary/Xnor.hpp"
#include "components/elementary/Xor.hpp"
#include "components/IComponent.hpp"
#include "components/composite/ActiveHighSrLatch.hpp"
#include "components/composite/DLatch.hpp"
#include "components/composite/FourBitAdder.hpp"
#include "components/composite/FullBitAdder.hpp"
#include "components/composite/HalfAdder.hpp"
#include "components/special/Clock.hpp"
#include "components/special/False.hpp"
#include "components/special/Input.hpp"
#include "components/special/Output.hpp"
#include "components/special/True.hpp"
#include "parser/Parser.hpp"

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

    _factory.registerCreator<FourAnd>(FOUR_AND_TYPE);
    _factory.registerCreator<FourNand>(FOUR_NAND_TYPE);
    _factory.registerCreator<FourOr>(FOUR_OR_TYPE);
    _factory.registerCreator<FourNor>(FOUR_NOR_TYPE);
    _factory.registerCreator<FourXor>(FOUR_XOR_TYPE);
    _factory.registerCreator<SixInverter>(SIX_INVERTER_TYPE);
    _factory.registerCreator<HalfAdder>(HALF_ADDER_TYPE);
    _factory.registerCreator<FullBitAdder>(FULL_ADDER_TYPE);
    _factory.registerCreator<ActiveHighSRLatch>(ACTIVE_HIGH_SR_LATCH);
    _factory.registerCreator<DLatch>(D_LATCH);
    _factory.registerCreator<FourBitAdder>(FOUR_BIT_ADDER_TYPE);
}

void Circuit::simulate(const std::size_t &tick)
{
    ++_tick;

    for (auto &[component, state]: _inputs | std::views::values) {
        component->simulate(tick);
        state = component->compute(1);
    }

    for (auto &[component, state]: _output | std::views::values) {
        component->simulate(tick);
        state = component->compute(1);
    }
}

Tristate Circuit::compute(const std::size_t &)
{
    std::cout << "tick: " << _tick << std::endl;

    std::cout << "input(s): " << std::endl;
    for (const auto &[chipsetName, node]: _inputs) {
        const auto &[component, state] = node;
        std::cout << "  " << chipsetName << ": " << state << std::endl;
    }

    std::cout << "output(s): " << std::endl;
    for (const auto &[chipsetName, node]: _output) {
        const auto &[component, state] = node;
        std::cout << "  " << chipsetName << ": " << state << std::endl;
    }

    return Tristate::UNDEFINED;
}

void Circuit::setLink(
    const std::size_t &pin, IComponent &other, const std::size_t &otherPin)
{
    AComponent::setLink(pin, other, otherPin);
}

void Circuit::setChipset(
    std::vector<std::pair<ChipsetType, ChipsetName>> &&chipsets)
{
    for (const auto &[chipsetType, chipsetName]: chipsets) {
        try {
            auto component = _factory.create(chipsetType, chipsetName);

            saveIfInputOrOutput(chipsetType, chipsetName, component.get());

            _chipsets.push_back(std::move(component));

        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void Circuit::init()
{
    for (auto &node: _inputs | std::views::values) {
        auto &[component, state] = node;

        state = component->compute(1);
    }

    for (auto &node: _output | std::views::values) {
        auto &[component, state] = node;

        state = component->compute(1);
    }
}

void Circuit::linkChipsets(std::vector<Link> &&links)
{
    for (const auto &[node1, node2]: links) {
        auto chipset1 = std::ranges::find_if(
            _chipsets, [node1](const std::unique_ptr<IComponent> &chipset) {
                return node1.first == chipset->getName();
            });
        auto chipset2 = std::ranges::find_if(
            _chipsets, [node2](const std::unique_ptr<IComponent> &chipset) {
                return node2.first == chipset->getName();
            });

        if (chipset1 == _chipsets.end() || chipset2 == _chipsets.end()) {
            throw std::runtime_error("Unknown chipset");
        }

        (*chipset1)->setLink(node1.second, **chipset2, node2.second);
    }

    init();
}

void Circuit::setInput(const ChipsetName &chipsetName, const std::string &value)
{
    const auto temp = std::ranges::find_if(
        _chipsets, [chipsetName](const std::unique_ptr<IComponent> &component) {
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
    const ChipsetName &chipsetName, IComponent *chipset)
{
    if (chipsetType == INPUT_TYPE || chipsetType == TRUE_TYPE ||
        chipsetType == FALSE_TYPE || chipsetType == CLOCK_TYPE) {
        _inputs[chipsetName] = std::pair{chipset, chipset->compute(1)};
    }
    if (chipsetType == OUTPUT_TYPE) {
        _output[chipsetName] = std::pair{chipset, chipset->compute(1)};
    }
}
} // namespace nts
