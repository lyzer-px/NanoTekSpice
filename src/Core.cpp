/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "Core.hpp"
#include "Circuit.hpp"
#include <exception>
#include <memory>
#include <utility>

nts::Core::Core(const std::string &filename) noexcept : _parser(filename) {}

void nts::Core::run()
{
    try {
        this->_parser.start();
        std::vector<std::pair<nts::ChipsetType, nts::ChipsetName>> chipsets = this->_parser.getChipsets();
        std::vector<nts::Link> links = this->_parser.getLinks();
        // std::dynamic_cast<Circuit *>(this->_circuit.get());
        auto *tmp = dynamic_cast<Circuit *>(_circuit.get());
        tmp->setChipset(chipsets);
        tmp->linkChipsets(links);
    } catch (const std::exception &e) {
        throw;
    }
}
