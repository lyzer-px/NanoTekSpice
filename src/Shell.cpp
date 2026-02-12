/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Shell
*/

#include "Shell.hpp"

inline const char * ShellExitException::what() const noexcept
{
    return "";
}

// inline ShellCommandNotFound::ShellCommandNotFound(const std::string& commandName)
// {
//     _message = commandName + ": command not found";
// }

inline const char * ShellCommandNotFound::what() const noexcept
{
    return _message.c_str();
}
