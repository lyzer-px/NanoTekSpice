/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsDisplayCommand
*/


#include <iostream>

#include "commands/NtsDisplayCommand.hpp"
#include "shell/NtsShell.hpp"

namespace nts {
bool NtsDisplayCommand::operator()(shell::Shell &shell,
    std::vector<std::string>)
{
    const auto &ntsShell = dynamic_cast<NtsShell &>(shell);

    ntsShell.getCircuit()->compute(0);
    return true;
}

bool NtsDisplayCommand::execute(shell::Shell &shell,
    const std::vector<std::string> cmd)
{
    return operator ()(shell, cmd);
}

std::unique_ptr<shell::IShellCommand> NtsDisplayCommand::create()
{
    return std::unique_ptr<IShellCommand>(new NtsDisplayCommand());
}
} // nts
