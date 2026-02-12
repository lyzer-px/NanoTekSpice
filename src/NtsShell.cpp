/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NtsShell
*/

#include "NtsShell.hpp"

#include "NtsDisplayCommand.hpp"
#include "ShellCommandNotFound.hpp"

namespace nts {
NtsShell::NtsShell(): Shell("nts_shell", "> ")
{
    _shellCommandFactory.registerCreator("display", NtsDisplayCommand::create);
}
} // nts
