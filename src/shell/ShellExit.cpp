/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ShellExit
*/

#include "ShellExit.hpp"
#include "ShellExitException.hpp"

namespace shell {
bool ShellExit::operator()(Shell &,
    std::vector<std::string>)
{
    throw ShellExitException();
}

bool ShellExit::execute(Shell &shell,
    const std::vector<std::string> cmd)
{
    return operator()(shell, cmd);
}

std::unique_ptr<IShellCommand> ShellExit::create()
{
    return std::unique_ptr<IShellCommand>(new ShellExit());
}
}
