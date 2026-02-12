/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ShellExit
*/

#pragma  once

#include "ShellExit.hpp"
#include "ShellExitException.hpp"

namespace shell {
template <typename ShellType>
bool ShellExit<ShellType>::operator()(ShellType &,
    std::vector<std::string>)
{
    throw ShellExitException();
}

template <typename ShellType>
bool ShellExit<ShellType>::execute(ShellType &shell,
    const std::vector<std::string> cmd)
{
    return operator()(shell, cmd);
}

template <typename ShellType>
std::unique_ptr<IDefaultShellCommand<ShellType>> ShellExit<ShellType>::create()
{
    return std::unique_ptr<IDefaultShellCommand<ShellType>>(new ShellExit());
}
}
