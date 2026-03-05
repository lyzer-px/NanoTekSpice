/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** types
*/

#ifndef NANOTEKSPICE_TYPES_HPP
#define NANOTEKSPICE_TYPES_HPP

#include <cstddef>
#include <string>

namespace nts {
using ChipsetName = std::string;
using ChipsetType = std::string;
using PinNumber   = std::size_t;
using Token       = std::string;
using ParsedChipsets = std::vector<std::pair<ChipsetName, ChipsetType>>;
using ParsedChipset = std::pair<ChipsetName, ChipsetType>;

struct Link {
    Link(const ChipsetName &chipset1Name, std::size_t chipset1Pin,
        const ChipsetName &chipset2Name, std::size_t chipset2Pin);

    std::pair<ChipsetName, PinNumber> component1;
    std::pair<ChipsetName, PinNumber> component2;
};
}

#endif // NANOTEKSPICE_TYPES_HPP
