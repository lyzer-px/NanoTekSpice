/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsShell
*/

#ifndef NANOTEKSPICE_NTSSHELL_HPP
#define NANOTEKSPICE_NTSSHELL_HPP

#include "IComponent.hpp"
#include "Shell.hpp"

namespace nts {
class Circuit;

class NtsShell: public shell::Shell {
public:
    NtsShell();

    void setCircuit(std::unique_ptr<IComponent> &circuit);

    IComponent *getCircuit() const noexcept;

private:
    std::unique_ptr<IComponent> _circuit;
};
} // nts

#endif //NANOTEKSPICE_NTSSHELL_HPP
