/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Shell
*/

#include "Shell.hpp"

namespace shell {
const char *ShellCommandNotFound::what() const noexcept
{
    return _message.c_str();
}
}
