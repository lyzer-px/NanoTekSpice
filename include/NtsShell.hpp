/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsShell
*/

#ifndef NANOTEKSPICE_NTSSHELL_HPP
#define NANOTEKSPICE_NTSSHELL_HPP

#include "Circuit.hpp"
#include "INtsCommand.hpp"
#include "Shell.hpp"

namespace nts {
class Circuit;

class NtsShell: public shell::Shell<nts::INtsCommand> {
public:
    NtsShell();

private:
    std::unique_ptr<Circuit> _circuit;
    bool executeExternCommand(const std::vector<std::string> &cmd) override;
};
} // nts

#endif //NANOTEKSPICE_NTSSHELL_HPP
