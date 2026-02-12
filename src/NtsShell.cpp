/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsShell
*/

#include "NtsShell.hpp"

#include "NtsDisplayCommand.hpp"

namespace nts {
NtsShell::NtsShell(): Shell("nts_shell", "> ")
{
    _externCommandFactory.registerCreator("display", NtsDisplayCommand::create);
}

bool NtsShell::executeExternCommand(const std::vector<std::string> &cmd)
{
    try {
        const auto command = _externCommandFactory.create(cmd[0]);
        return command->execute(*_circuit, cmd);
    } catch (const std::exception &e) {
        throw shell::ShellCommandNotFound(cmd[0]);
    }
}
} // nts
