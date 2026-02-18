/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsShell
*/

#include <iostream>

#include "NtsShell.hpp"
#include "NtsDisplayCommand.hpp"
#include "ShellCommandNotFound.hpp"

namespace nts {
NtsShell::NtsShell(): Shell("nts_shell", "> ")
{
    _shellCommandFactory.registerCreator<NtsDisplayCommand>("display");
}

void NtsShell::setCircuit(std::unique_ptr<IComponent> &circuit)
{
    _circuit = std::move(circuit);
}

IComponent * NtsShell::getCircuit() const noexcept
{
    return _circuit.get();
}
} // nts
