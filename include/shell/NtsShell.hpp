/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsShell
*/

#ifndef NANOTEKSPICE_NTSSHELL_HPP
#define NANOTEKSPICE_NTSSHELL_HPP

#include "Circuit.hpp"
#include "IComponent.hpp"
#include "Shell.hpp"

namespace nts {
class Circuit;

class NtsShell: public shell::Shell {
public:
    explicit NtsShell(Circuit *circuit);

    void setCircuit(Circuit *circuit);

    Circuit *getCircuit() const noexcept;

    bool executeCommand(const std::vector<std::string> &cmd) override;

private:
    Circuit *_circuit;
};
} // nts

#endif //NANOTEKSPICE_NTSSHELL_HPP
