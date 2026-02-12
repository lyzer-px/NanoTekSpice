/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ShellExit
*/

#include "ShellExit.hpp"

#include "Shell.hpp"

bool ShellExit::operator()(Shell<> &,
    std::vector<std::string>)
{
    throw ShellExitException();
}

bool ShellExit::execute(Shell<> &shell,
    const std::vector<std::string> cmd)
{
    return operator()(shell, cmd);
}

std::unique_ptr<IDefaultShellCommand> ShellExit::create()
{
    return std::unique_ptr<IDefaultShellCommand>(new ShellExit());
}
