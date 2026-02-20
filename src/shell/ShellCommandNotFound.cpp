/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ShellCommandNotFound
*/

#include "shell/ShellCommandNotFound.hpp"

namespace shell {
const char *ShellCommandNotFound::what() const noexcept
{
    return _message.c_str();
}
} // namespace shell
