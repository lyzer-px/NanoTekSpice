/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Shell
*/

#include "Shell.hpp"

namespace shell {
inline const char *ShellExitException::what() const noexcept
{
    return "";
}

inline const char *ShellCommandNotFound::what() const noexcept
{
    return _message.c_str();
}
}
