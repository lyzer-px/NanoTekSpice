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
#include "NtsSetInputCommand.hpp"
#include "NtsSimulateCommand.hpp"
#include "ShellCommandNotFound.hpp"
#include "ShellExitException.hpp"

namespace nts {
NtsShell::NtsShell(Circuit *circuit): Shell("nts_shell", "> "),
    _circuit(circuit)
{
    _shellCommandFactory.registerCreator<NtsDisplayCommand>("display");
    _shellCommandFactory.registerCreator<NtsSimulateCommand>("simulate");
    _shellCommandFactory.registerCreator<NtsLoopCommand>("loop");
    _shellCommandFactory.registerCreator<NtsSetInputCommand>("setInput");
}

void NtsShell::setCircuit(Circuit *circuit)
{
    _circuit = circuit;
}

Circuit *NtsShell::getCircuit() const noexcept
{
    return _circuit;
}

bool NtsShell::executeCommand(const std::vector<std::string> &cmd)
{
    try {
        return Shell::executeCommand(cmd);
    }  catch (const shell::ShellExitException &) {
        throw;
    } catch (...) {
        try {
            const auto setCommand = _shellCommandFactory.create("setInput");

            return (*setCommand)(*this, cmd);
        } catch (const std::exception &) {
            std::cerr << cmd[0] << ": command not found" << std::endl;

            return false;
        }
    }
}
} // nts
