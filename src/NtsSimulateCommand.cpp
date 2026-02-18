/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsSimulateCommand
*/

#include "NtsSimulateCommand.hpp"

#include "NtsShell.hpp"

namespace nts {
bool NtsSimulateCommand::operator()(shell::Shell &shell,
    std::vector<std::string>)
{
    const auto &ntsShell = dynamic_cast<NtsShell &>(shell);

    ntsShell.getCircuit()->simulate(0);

    return true;
}

bool NtsSimulateCommand::execute(shell::Shell &shell,
    const std::vector<std::string> cmd)
{
    return (*this)(shell, cmd);
}

std::unique_ptr<shell::IShellCommand> NtsSimulateCommand::create()
{
    return std::make_unique<NtsSimulateCommand>();
}
} // nts