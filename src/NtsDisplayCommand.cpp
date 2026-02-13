/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsDisplayCommand
*/

#include "../include/NtsDisplayCommand.hpp"

#include <iostream>

namespace nts {
bool NtsDisplayCommand::operator()(shell::Shell &shell,
    std::vector<std::string> cmd)
{
    std::clog << "Nts display command" << std::endl;
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
