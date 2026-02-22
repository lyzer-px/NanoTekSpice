/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsSetInputCommand
*/


#include <iostream>

#include "commands/NtsSetInputCommand.hpp"
#include "shell/NtsShell.hpp"
#include "StringUtils.hpp"

namespace nts {
bool NtsSetInputCommand::operator()(shell::Shell &shell,
    std::vector<std::string> cmd)
{
    if (cmd.size() != 1)
        throw std::logic_error("Bad command");

    const auto splited = strutils::splitStr(cmd[0], '=');
    if (splited.size() != 2)
        throw std::logic_error("Bad command");

    const auto &ntsShell = dynamic_cast<NtsShell &>(shell);

    try {
        ntsShell.getCircuit()->setInput(splited[0], splited[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}

bool NtsSetInputCommand::execute(shell::Shell &shell,
    const std::vector<std::string> cmd)
{
    return (*this)(shell, cmd);
}

std::unique_ptr<shell::IShellCommand> NtsSetInputCommand::create()
{
    return std::make_unique<NtsSetInputCommand>();
}
} // nts
