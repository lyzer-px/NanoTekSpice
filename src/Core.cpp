/*
** EPITECH PROJECT, 2026
** OOP
** File description:
** 
*/

#include "Core.hpp"
#include "components/Circuit.hpp"
#include <exception>
#include <memory>
#include <utility>

nts::Core::Core(const std::string &filename) noexcept: _parser(filename),
    _customParser{filename},
    _circuit{std::make_unique<Circuit>("circuit")}
{
    _shell = std::make_unique<NtsShell>(
        dynamic_cast<Circuit *>(this->_circuit.get()));
}

void nts::Core::run()
{
    try {
        this->_parser.start();
        //this->_customParser.parse();

        auto *circuit = dynamic_cast<Circuit *>(this->_circuit.get());
        circuit->setChipset(this->_parser.getChipsets());
        circuit->linkChipsets(this->_parser.getLinks());

        _shell->setCircuit(circuit);
        _shell->run();

    } catch (const std::exception &e) {
        throw;
    }
}
