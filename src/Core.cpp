/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "Core.hpp"
#include <exception>
#include <iostream>
#include <utility>

nts::Core::Core(std::string filename) noexcept : _parser(std::move(filename)) {}

void nts::Core::run()
{
    try {
        this->_parser.start();
        std::vector<std::pair<nts::ChipsetType, nts::ChipsetName>> chipsets = this->_parser.getChipsets();
        std::vector<nts::Link> links = this->_parser.getLinks();
    } catch (const std::exception &e) {
        throw;
    }
}
