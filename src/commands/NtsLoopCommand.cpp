/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsLoopCommand
*/

#include "../include/NtsLoopCommand.hpp"

#include "NtsShell.hpp"

namespace nts {
bool NtsLoopCommand::operator()(shell::Shell &shell,
    std::vector<std::string>)
{
    const auto &ntsShell = dynamic_cast<NtsShell &>(shell);

    while (true) {
        ntsShell.getCircuit()->simulate(0);
        ntsShell.getCircuit()->compute(0);
    }

    return true;
}

bool NtsLoopCommand::execute(shell::Shell &shell, std::vector<std::string> cmd)
{
    return (*this)(shell, cmd);
}

std::unique_ptr<shell::IShellCommand> NtsLoopCommand::create()
{
    return std::make_unique<NtsLoopCommand>();
}
} // nts
