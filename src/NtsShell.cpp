/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsShell
*/

#include <iostream>

#include "NtsShell.hpp"
#include "NtsDisplayCommand.hpp"
#include "NtsLoopCommand.hpp"
#include "NtsSimulateCommand.hpp"
#include "ShellCommandNotFound.hpp"

namespace nts {
NtsShell::NtsShell(): Shell("nts_shell", "> ")
{
    _shellCommandFactory.registerCreator<NtsDisplayCommand>("display");
    _shellCommandFactory.registerCreator<NtsSimulateCommand>("simulate");
    _shellCommandFactory.registerCreator<NtsLoopCommand>("loop");
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
